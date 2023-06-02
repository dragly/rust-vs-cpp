struct Test {
    x: f32
}

fn main() {
    {
        let a = Test { x: 10.0 };
    }
    {
        let b = Test {};
        println!("x is {}", b.x);
    }
}
