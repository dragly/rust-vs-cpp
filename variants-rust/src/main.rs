enum Command {
    Message(String),
    Multiply { a: f32, b: f32 },
    StatusOK,
}

fn act(command: Command) {
    match command {
        Command::Message(s) => println!("{s}"),
        Command::Multiply { a, b } => {
            let result = a * b;
            println!("{result:.2}");
        }
        Command::StatusOK => println!("Everything will be alright"),
    }
}

fn main() {
    act(Command::Message("Hello".to_owned()));
    act(Command::Multiply { a: 1.1, b: 3.2 });
    act(Command::StatusOK);

    let colorBuffer;

    if (1.2 > 1.2) {
        colorBuffer = 4;
    } else {
        colorBuffer = 5;
    }

    let colorBuffer = match (1.2) {
        1.2 => 4,
        _ => 5,
    };
}
