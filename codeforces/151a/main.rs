use std::io::{self, BufRead};

fn min(v: Vec<i32>) -> i32 {
    return v
        .iter()
        .fold(10000, |acc, &x| if acc < x { acc } else { x });
}

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();

    let v = buf
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect::<Vec<i32>>();
    let drink = (v[1] * v[2]) / v[6];
    let lime = v[3] * v[4];
    let salt = v[5] / v[7];

    let ans = min(vec![drink, lime, salt]);
    println!("{:?}", ans / v[0]);
}
