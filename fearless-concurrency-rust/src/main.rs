use rayon::prelude::*;

fn main() {
    let numbers = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

    let sum_of_squares: i32 = numbers.par_iter()
        .filter(|&x| x % 2 == 0)
        .map(|&x| x * x)
        .sum();

    println!("The sum of the squares of even numbers is: {}", sum_of_squares);
}
