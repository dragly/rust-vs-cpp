#include <fmt/ranges.h>
#include <iostream>
#include <vector>

int main() {
  bool something = false;
  int value;
  fmt::print("{}\n", value);
  if (something) {
    value = 42;
  } else {
    value = 44;
  }
  fmt::print("{}\n", value);
}
