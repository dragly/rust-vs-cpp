#include <fmt/ranges.h>

#include <thread>

int main()
{
    int shared = 0;

    auto thread1 = std::thread([&shared] {
        for (int i = 0; i < 10000; i++) {
            if (shared % 2) {
                fmt::println("{} is even", shared);
            }
            shared += 1;
        }
    });
    auto thread2 = std::thread([&shared] {
        for (int i = 0; i < 10000; i++) {
            if ((shared % 2) == 1) {
                fmt::println("{} is odd", shared);
            }
            shared += 1;
        }
    });

    thread1.join();
    thread2.join();

    return 0;
}
