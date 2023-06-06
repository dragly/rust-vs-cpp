# Variants

Create a function called `act` that accepts a "command"
that can be one of these three kinds, each with a respective action:

- a message that is printed to screen
- two numbers that are multiplied and then printed
- the status OK, which causes the program to print "Everything will be alright!"

The Command needs to be a type of its own so that parts of the code
can be agnostic to the underlying type of command.

The program can look something like

```cpp
int main() {
    const auto message = // Message with "Hello" stored as a string
    const auto multiply = // Multiply with a = 1.1 and b = 3.2
    const auto statusOK = // Status OK
    act(message); // prints "Hello"
    act(multiply); // prints 3.5200002
    act(statusOK); // prints "Everything will be alright!"
}
```

You are supposed to implement the types for Message, Multiply and StatusOK.
