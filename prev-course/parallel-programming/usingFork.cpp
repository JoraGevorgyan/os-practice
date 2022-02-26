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


void using_child()
{
	std::cout << "message from child" << std::endl;
}


void using_parent()
{
	std::cout << "message from parent" << std::endl;
}

int main()
{
	int child = fork();
	check(child);

	if (child == 0)
	{
		using_child();
	}
	else
	{
		using_parent();
	}
	
	std::cout << "this part will be ran by both processes" << std::endl;

	return 0;
}
