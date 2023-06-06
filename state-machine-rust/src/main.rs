enum Player {
    Idle,
    Sleeping { time: f32 },
    Eating { amount: f32 },
    Dead,
}

fn ask(message: &str) -> String {
    println!("{}", message);
    let mut input = String::new();
    match std::io::stdin().read_line(&mut input) {
        Ok(_) => input.trim(),
        Err(_) => "",
    }.to_owned()
}

fn main() {
    let mut player = Player::Idle;
    loop {
        player = match player {
            Player::Idle => {
                match ask("Ferris is waiting... Should it sleep or eat?").as_str() {
                    "eat" => Player::Eating { amount: 1.0 },
                    "sleep" => Player::Sleeping { time: 1.0 },
                    _ => player,
                }
            }
            Player::Sleeping { time } => {
                match ask("Ferris is sleeping... Should it continue or wake up?").as_str() {
                    "continue" => Player::Sleeping { time: time + 1.0 },
                    "wake up" => Player::Idle,
                    _ => player,
                }
            }
            Player::Eating { amount } => {
                match ask("Ferris is eating... Should it continue or stop?").as_str() {
                    "continue" => {
                        if amount > 2.0 {
                            Player::Dead
                        } else {
                            Player::Eating {
                                amount: amount + 1.0,
                            }
                        }
                    }
                    "stop" => Player::Idle,
                    _ => player,
                }
            }
            Player::Dead => {
                ask("Ferris is dead");
                player
            }
        }
    }
}
