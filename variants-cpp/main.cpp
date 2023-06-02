#include <fmt/core.h>
#include <fmt/ranges.h>
#include <iostream>
#include <memory>
#include <variant>
#include <vector>

// ---- VARIANTS ----

namespace variants {
template <typename... Ts> struct Overloader : Ts... {
  using Ts::operator()...;
};

template <typename... Ts> Overloader(Ts...) -> Overloader<Ts...>;

struct Message {
  std::string contents;
};

struct Multiply {
  float a;
  float b;
};

struct StatusOK {};

using Command = std::variant<Message, Multiply, StatusOK>;

void act(const Command &command) {
  std::visit(
      Overloader{
          [](const Message &message) { fmt::println("{}", message.contents); },
          [](const Multiply &multiply) {
            fmt::println("{}", multiply.a * multiply.b);
          },
          [](const StatusOK &) { fmt::println("Everything will be alright!"); },
      },
      command);
}
void run() {
  act(Message{"Hello"});
  act(Multiply{1.1, 3.2});
  act(StatusOK{});
}
} // namespace variants

// ----- INHERITANCE -----

namespace inheritance {
class Command {
public:
  virtual ~Command() = default;
  virtual void act() = 0;
};

class Message : public Command {
public:
  Message(std::string contents) : m_contents(contents) {}
  void act() override { fmt::println("{}", m_contents); }

private:
  std::string m_contents;
};

struct Multiply : public Command {
public:
  Multiply(float a, float b) : m_a(a), m_b(b) {}
  void act() override { fmt::println("{}", m_a * m_b); }

private:
  float m_a;
  float m_b;
};

struct StatusOK : public Command {
public:
  void act() override { fmt::println("Everything will be alright!"); }
};

void act(std::unique_ptr<Command> command) { command->act(); }

void run() {
  act(std::make_unique<Message>("Hello"));
  act(std::make_unique<Multiply>(1.1, 3.2));
  act(std::make_unique<StatusOK>());
}
} // namespace inheritance

// ----- TEMPLATES -----

namespace templates {
struct Message {
  std::string contents;
};

struct Multiply {
  float a;
  float b;
};

struct StatusOK {};

template <typename T> struct Command {
  T value;
};

template <typename T> void act(const Command<T> &command);

template <> void act(const Command<Message> &message) {
  fmt::println("{}", message.value.contents);
}

template <> void act(const Command<Multiply> &multiply) {
  fmt::println("{}", multiply.value.a * multiply.value.b);
}

template <> void act(const Command<StatusOK> &) {
  fmt::println("Everything will be alright!");
}

void run() {
  act(Command<Message>{Message{"Hello"}});
  act(Command<Multiply>{Multiply{1.1, 3.2}});
  act(Command<StatusOK>{StatusOK{}});
}
} // namespace templates

// ----- ENUMS -----

namespace enums {
struct Message {
  std::string contents;
};

struct Multiply {
  float a;
  float b;
};

struct StatusOK {};

enum class Command {
  message,
  multiply,
  statusOK,
};

void act(const Command &command) {
  switch (command) {
  case Command::message:
    fmt::println("...");
  case Command::multiply:
    fmt::println("...");
  case Command::statusOK:
    fmt::println("Everything will be alright!");
  }
}
void run() {
  act(Command::message);
  act(Command::multiply);
  act(Command::statusOK);
}
} // namespace enums

// --------------------------

int main() {
  fmt::println("\n\nVariants:");
  variants::run();

  fmt::println("\n\nInheritance:");
  inheritance::run();

  fmt::println("\n\nTemplates:");
  templates::run();

  fmt::println("\n\nEnums:");
  enums::run();
}

// Things to explore
// - Remove one of the arms in the visit and compare the compiler errors
