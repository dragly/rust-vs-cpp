#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <variant>

template <typename... Ts>
struct Overloader : Ts... {
    using Ts::operator()...;
};

template <typename... Ts>
Overloader(Ts...) -> Overloader<Ts...>;

struct Idle { };
struct Dead { };

struct Sleeping {
    float time;
};

struct Eating {
    float amount;
};

using PlayerState = std::variant<Idle, Sleeping, Eating, Dead>;

std::string ask(const std::string& message)
{
    std::cout << message << std::endl;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int main()
{
    PlayerState player = Idle {};

    while (true) {
        player = std::visit(
            Overloader {
                [=](Idle&) -> PlayerState {
                    std::string choice = ask("Ferris is waiting... Should it sleep or eat?");
                    if (choice == "eat") {
                        return Eating { 1.0 };
                    } else if (choice == "sleep") {
                        return Sleeping { 1.0 };
                    } else {
                        return player;
                    }
                },
                [=](Sleeping& sleeping) -> PlayerState {
                    std::string choice = ask("Ferris is sleeping... Should it continue or wake up?");
                    if (choice == "continue") {
                        sleeping.time += 1.0;
                        return sleeping;
                    } else if (choice == "wake up") {
                        return Idle {};
                    } else {
                        return player;
                    }
                },
                [=](Eating& eating) -> PlayerState {
                    std::string choice = ask("Ferris is eating... Should it continue or stop?");
                    if (choice == "continue") {
                        if (eating.amount > 2.0) {
                            return Dead {};
                        } else {
                            eating.amount += 1.0;
                            return eating;
                        }
                    } else if (choice == "stop") {
                        return Idle {};
                    } else {
                        return player;
                    }
                },
                [=](Dead&) -> PlayerState {
                    ask("Ferris is dead");
                    return player;
                },
            },
            player);
    }

    return 0;
}
