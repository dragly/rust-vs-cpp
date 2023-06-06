use std::thread;

#[derive(Debug)]
struct Shared {
    value: i32,
}

fn main() {
    let mut shared = Shared { value: 0 };

    let t1 = thread::spawn(move || {
        for _ in 0..1000 {
            if (shared.value % 2) == 0 {
                println!("{} is even", shared.value);
            }
            shared.value += 1;
        }
    });

    let t2 = thread::spawn(move || {
        for _ in 0..1000 {
            if (shared.value % 2) == 1 {
                println!("{} is odd", shared.value);
            }
            shared.value += 1;
        }
    });

    t1.join().unwrap();
    t2.join().unwrap();
}
