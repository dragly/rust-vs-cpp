#include <iostream>
#include <memory>
#include <type_traits>

// ----- CONCEPTS -----

namespace concepts {
template <typename T>
concept Shape = requires(T shape) {
    {
        shape.area()
    } -> std::convertible_to<double>;
};

struct Rectangle {
    double area() const
    {
        return width_ * height_;
    }

    double width_;
    double height_;
};

struct Circle {
    double area() const
    {
        return 3.14159 * radius_ * radius_;
    }

    double radius_;
};

void printArea(const Shape auto& shape)
{
    std::cout << "Area: " << shape.area() << std::endl;
}

void run()
{
    Rectangle rectangle { 4.0, 5.0 };
    Circle circle { 2.5 };

    printArea(rectangle);
    printArea(circle);
}
}

// ----- INHERITANCE -----

namespace inheritance {
struct Shape {
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

struct Rectangle : public Shape {
    Rectangle(double width, double height)
        : width_(width)
        , height_(height)
    {
    }
    double area() const override
    {
        return width_ * height_;
    }

    double width_;
    double height_;
};

struct Circle : public Shape {
    Circle(double radius)
        : radius_(radius)
    {
    }
    double area() const override
    {
        return 3.14159 * radius_ * radius_;
    }

    double radius_;
};

void printArea(const Shape& shape)
{
    std::cout << "Area: " << shape.area() << std::endl;
}

void run()
{
    auto rectangle = std::make_unique<Rectangle>(4.0, 5.0);
    auto circle = std::make_unique<Circle>(2.5);

    printArea(*rectangle);
    printArea(*circle);
}
}

// -----------------------

int main()
{
    concepts::run();
    inheritance::run();
    return 0;
}
