#include <bits/stdc++.h>
#include <pthread.h>

constexpr int loopCount = 1000000;

void check(int err)
{
	if (err != 0)
	{
		std::cerr << "error happened" << std::endl;
		exit(err);
	}
}

int tmp = 0;

void* foo(void* arg)
{
	for (int i = 0; i < loopCount; ++i)
	{
		++tmp;
	}

	return nullptr;
}

int main()
{
	constexpr int threadsCount = 4;
	
	pthread_t* allThreads = new pthread_t[threadsCount];

	for (int i = 0; i < threadsCount; ++i)
	{
		int err = pthread_create(&allThreads[i], nullptr, &foo, nullptr);
		check(err);
	}

	for (int i = 0; i < threadsCount; ++i)
	{
		int err = pthread_join(allThreads[i], nullptr);
		check(err);	
	}
	
	delete[] allThreads;

	std::cout << "expected: " << loopCount * threadsCount << std::endl;
	std::cout << "received: " << tmp << std::endl;
	return 0;
}
