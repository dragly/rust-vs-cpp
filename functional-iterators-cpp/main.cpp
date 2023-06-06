#include <fmt/ranges.h>
#include <range/v3/all.hpp>
#include <vector>

int main()
{
    auto numbers = std::vector<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    const auto sum_of_squares = ranges::accumulate(numbers | ranges::views::filter([](int a) { return a % 2 == 0; })
            | ranges::views::transform([](int x) { return x * x; }),
        0);

    fmt::println("The sum of the squares of even numbers is: {}", sum_of_squares);

    return 0;
}
