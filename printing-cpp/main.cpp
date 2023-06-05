#include <chrono>
#include <fmt/chrono.h>
#include <fmt/ranges.h>
#include <iostream>
#include <vector>

struct Presentation {
  std::string topic;
  std::chrono::year_month_day date;
};

template <> struct fmt::formatter<Presentation> {
  template <typename ParseContext> constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(const Presentation &presentation, FormatContext &ctx) {
    return fmt::format_to(
        ctx.out(), "Presentation {{ topic: \"{}\", date: {}-{}-{} }}",
        presentation.topic, static_cast<int>(presentation.date.year()),
        static_cast<unsigned>(presentation.date.month()),
        static_cast<unsigned>(presentation.date.day()));
  }
};

int main() {
  const auto presentation = Presentation{
      "Rust vs C++",
      std::chrono::year_month_day(std::chrono::year(2023),
                                  std::chrono::month(6), std::chrono::day(5)),
  };

  fmt::println("The presentation is {}", presentation);

  return 0;
}
