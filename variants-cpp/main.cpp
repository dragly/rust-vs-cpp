#include <fmt/core.h>
#include <fmt/ranges.h>
#include <iostream>
#include <memory>
#include <variant>
#include <vector>

// ---- VARIANTS ----

// Things to explore
//
// - Remove one of the arms in the visit and compare the compiler errors to Rust

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

// ----- OVERLOADS -----

namespace overloads {
struct Message {
  std::string contents;
};

struct Multiply {
  float a;
  float b;
};

struct StatusOK {};

void act(const Message &message) { fmt::println("{}", message.contents); }

void act(const Multiply &multiply) {
  fmt::println("{}", multiply.a * multiply.b);
}

void act(const StatusOK &) { fmt::println("Everything will be alright!"); }

void run() {
  act(Message{"Hello"});
  act(Multiply{1.1, 3.2});
  act(StatusOK{});
}
} // namespace overloads

// ----- ENUMS -----

namespace enums {

struct CommandBase {
  virtual ~CommandBase() = default;
};

struct Message : public CommandBase {
  Message(std::string c) : contents(c) {}
  std::string contents;
};

struct Multiply : public CommandBase {
  Multiply(float a_, float b_) : a(a_), b(b_) {}
  float a;
  float b;
};

struct StatusOK : public CommandBase {};

enum class Command {
  message,
  multiply,
  statusOK,
};

void act(const Command &command, std::unique_ptr<CommandBase> cmd) {
  switch (command) {
  case Command::message: {
    fmt::println("{}", dynamic_cast<Message *>(cmd.get())->contents);
    break;
  }
  case Command::multiply: {
    const auto multiply = dynamic_cast<Multiply *>(cmd.get());
    fmt::println("{}", multiply->a * multiply->b);
    break;
  }
  case Command::statusOK:
    fmt::println("Everything will be alright!");
    break;
  }
}
void run() {
  act(Command::message, std::make_unique<Message>("Hello"));
  act(Command::multiply, std::make_unique<Multiply>(1.1, 3.2));
  act(Command::statusOK, std::make_unique<StatusOK>());
}
} // namespace enums

// --------------------------

int main() {
  fmt::println("\n\nVariants:");
  variants::run();

  fmt::println("\n\nInheritance:");
  inheritance::run();

  fmt::println("\n\nTemplates:");
  overloads::run();

  fmt::println("\n\nEnums:");
  enums::run();
}
