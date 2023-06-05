#include <fmt/ranges.h>

#include <iostream>
#include <vector>

struct Test {
    float x;
};

int main()
{
    {
        Test a;
        a.x = 10;
    }
    {
        Test b;
        std::cout << "x is " << b.x << "!\n";
    }
}
