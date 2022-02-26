#!/bin/python3

def read_int() -> int:
    tmp = int(input("Enter some integer number: "))
    return tmp


def get_array(length: int) -> list:
    return [int(0)] * length


def read_array(array: list):
    for i in range(0, len(array)):
        array[i] = int(input())


def get_sum(array: list) -> int:
    sum = int(0)
    for tmp in array:
        sum += tmp

    return sum


def main():
    n = read_int()
    array = get_array(n)
    read_array(array)
    sum = get_sum(array)

    for i in array:
        print(i, end=' ')

    print("\nThe sum of these numbers is: ", str(sum))


if __name__ == "__main__":
    main()
