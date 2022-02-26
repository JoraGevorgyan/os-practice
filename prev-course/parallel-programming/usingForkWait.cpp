#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <bits/stdc++.h>

void check(int ret_value, const std::string& msg)
{
	if (ret_value == -1)
	{
		std::cerr << msg << std::endl;
		exit(errno);
	}
}


void using_child()
{
	std::cout << "message from child: " << getpid() << std::endl;
}

void using_parent()
{
    std::cout << "message from parent: " << getpid() << std::endl;
}

int main()
{
    using_parent();

	int child = fork();
	check(child, "failure when forking");

	if (child == 0)
	{
		using_child();
	}
	
    std::cout << "PID: " << getpid() << std::endl;

    if (child != 0)
    {
        int childExitCode = -1;
        pid_t waitingForChild = waitpid(child, &childExitCode, 0);
        check(waitingForChild,
              "failure when waiting for a child process, PID: " + std::to_string(child));
        std::cout << "the child process (PID: " << child
                  << " ) has done with exit code: " << childExitCode << std::endl;
    }
    return 0;
}
