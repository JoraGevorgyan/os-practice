#include <sys/types.h>
#include <unistd.h>

#include <bits/stdc++.h>

void check(int ret_value)
{
	if (ret_value == -1)
	{
		std::cerr << "something wrong when using fork" << std::endl;
		exit(errno);
	}
}


void using_child(int pid)
{
	std::cout << "child, got pid: " << pid << std::endl;
}


void using_parent(int pid)
{
	std::cout << "parent, got pid: " << pid << std::endl;
}

int main()
{
	int child = fork();
	check(child);

	if (child == 0)
	{
		using_child(child);
	}
	else
	{
		using_parent(child);
	}
	
	std::cout << "from: " << getpid() << std::endl;

	return 0;
}
