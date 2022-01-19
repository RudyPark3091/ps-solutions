use std::io::{self, Read};

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_to_string(&mut buf).unwrap();
    let v: Vec<i32> = buf
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect::<Vec<i32>>();
    let max = &v[..].into_iter().max().unwrap();
    let min = &v[..].into_iter().min().unwrap();
    println!("{}", **max - **min);
}
