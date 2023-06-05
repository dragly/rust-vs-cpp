trait Shape {
    fn area(&self) -> f64;
}

struct Rectangle {
    width: f64,
    height: f64,
}

impl Shape for Rectangle {
    fn area(&self) -> f64 {
        self.width * self.height
    }
}

struct Circle {
    radius: f64,
}

impl Shape for Circle {
    fn area(&self) -> f64 {
        3.14159 * self.radius * self.radius
    }
}

// The following is not possible in C++: To implement the concept for an existing external type.
use kurbo::Rect;

impl Shape for Rect {
    fn area(&self) -> f64 {
        let height = self.y1 - self.y0;
        let width = self.x1 - self.x0;
        width * height
    }
}

fn print_area(shape: &impl Shape) {
    println!("Area: {}", shape.area());
}

fn main() {
    let rectangle = Rectangle {
        width: 4.0,
        height: 5.0,
    };
    let circle = Circle { radius: 2.5 };
    let rect = Rect {
        x0: 1.0,
        y0: 2.1,
        x1: 3.0,
        y1: 4.0,
    };

    print_area(&rectangle);
    print_area(&circle);

    // Not possible in C++ because kurbo::Rect is external
    print_area(&rect);
}
