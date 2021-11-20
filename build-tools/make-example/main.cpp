#include "calculator.hpp"
#include "printer.hpp"

int main()
{
    int a = 0;
    int b = 0;
    std::cin >> a >> b;

    int sum = calculate_sum(a, b);
    print(std::to_string(a) + " + " + std::to_string(b) + " == " + std::to_string(sum));
    return 0;
}

