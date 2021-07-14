use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut arr = [0u8; 10];
    let x = stdin.lock().lines()
        .map(|x| x.unwrap().parse().unwrap())
        .fold(1u32, |acc, x: u32| acc * x)
        .to_string();
    for c in x.chars() {
        arr[c.to_digit(10).unwrap() as usize] += 1;
    }
    for i in arr.iter() {
        println!("{}", *i);
    }
}
