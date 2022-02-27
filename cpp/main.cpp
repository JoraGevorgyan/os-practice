#include <iostream>

int read_int()
{

	std::cout << "enter any int: ";
	int tmp;
	std::cin >> tmp;

	return tmp;
}


int* get_arr(int size)
{
	int* arr = new int[size];
	if (arr == nullptr)
	{
		exit(1);
	}
	return arr;
}


int main()
{
	int arr_size = read_int();
	
	int* arr = get_arr(arr_size);
	
	for (int i = 0; i < n; ++i)
	{

		arr[i] = read_int();
	}


	delete[] arr;
	return 0;
}
