use chrono::{Date, TimeZone, Utc};

#[derive(Debug)]
struct Presentation {
    topic: String,
    date: Date<Utc>,
}

fn main() {
    let presentation = Presentation {
        topic: "Rust vs C++".to_owned(),
        date: Utc.ymd(2023, 6, 5),
    };

    println!("The presentation is {:?}", presentation);
}
