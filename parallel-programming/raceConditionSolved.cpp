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

pthread_mutex_t* lockForTmp = nullptr;

int tmp = 0;

void* foo(void* arg)
{
	for (int i = 0; i < loopCount; ++i)
	{
		pthread_mutex_lock(lockForTmp);
		++tmp;
		pthread_mutex_unlock(lockForTmp);
	}

	return nullptr;
}

int main()
{
	constexpr int threadsCount = 4;
	
	pthread_t* allThreads = new pthread_t[threadsCount];
	lockForTmp = new pthread_mutex_t();
	int err = pthread_mutex_init(lockForTmp, nullptr);
	check(err);

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
	
	delete lockForTmp;
	delete[] allThreads;

	std::cout << "expected: " << loopCount * threadsCount << std::endl;
	std::cout << "received: " << tmp << std::endl;
	return 0;
}
