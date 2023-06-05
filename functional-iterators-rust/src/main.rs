use itertools::Itertools;

fn main() {
    let sentence = "these are a bunch of words that needs reversing";
    let output = sentence
        .split(" ")
        .map(|s| [s.to_string(), s.chars().rev().collect::<String>()])
        .flatten()
        .join("");
    println!("{:?}", output);
}
