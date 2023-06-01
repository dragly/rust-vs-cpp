fn main() {
    let mut values = vec![1, 2, 3, 4, 5];
    for value in &mut values {
        values.push(*value);
    }
}
