#include <fmt/ranges.h>
#include <vector>

int main() {
  auto values = std::vector<int>{1, 2, 3, 4};
  for (const auto value : values) {
    values.push_back(value);
  }
  fmt::print("{}\n", values);
}
