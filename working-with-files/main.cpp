/*
 * this is just a sample program which shows how we can use system calls
 * and work with files
 *
 *
 * the program will take rwo file paths from command-line argument
 * and copy the content of those files into "output.txt" file
 **/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>
#include <string>

void check(ssize_t value, const std::string& failure_msg)
{
	if (value == -1)
	{
		std::cerr << failure_msg << std::endl;
		std::cerr << "error code: " << errno << std::endl;
		exit(-1);
	}
}

int open_file(const char* file_path)
{
	int fd = open(file_path, O_RDONLY);
	check(fd, "something wrong when opening the file" + std::string(file_path));
	return fd;
}

int create_file(const char* file_path)
{
	int fd = creat(file_path, S_IWUSR | S_IREAD);
	check(fd, "something wrong when creating the file: " + std::string(file_path));
	return fd;
}

void close_file(int fd)
{
	int err = close(fd);
	check(err, "something wrong when closing the file");
}

void copy_info(int input_fd, int output_fd)
{
	while (true)
	{
		const int buf_size = 2048;
		char* buffer = new char[buf_size];

		ssize_t count = read(input_fd, buffer, buf_size);
		check(count, "error when reading from file!!");
		if (count == 0)
		{
			return;
		}
		ssize_t written = write(output_fd, buffer, count);
		check(written, "error when writing in file!!");
		delete[] buffer;
	}
}

int copy_files(int argc, char** argv);

int list_content(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "One path is required only!!" << std::endl;
		return -1;
	}

	return 0;
}

int main(int argc, char** argv)
{
//	return copy_files(argc, argv);
	return list_content(argc, argv);
}

int copy_files(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "two filenames are required!!" << std::endl;
		return -1;
	}
	int output = create_file("output.txt");

	int first = open_file(argv[1]);
	copy_info(first, output);
	close_file(first);

	int second = open_file(argv[2]);
	copy_info(second, output);
	close_file(second);

	close_file(output);
	return 0;
}
