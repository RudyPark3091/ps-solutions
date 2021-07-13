use std::io;
use std::io::BufRead;

fn fib(n: i32) -> i32 {
    let mut pair = (0, 1);
    for _ in 0..n {
        pair = (pair.1, pair.0 + pair.1);
    }
    pair.0
}

fn solve(n: i32) {
    if n == 0 {
        println!("1 0");
    } else {
        println!("{} {}", fib(n - 1), fib(n));
    }
}

fn main() {
    let stdin = io::stdin();
    let v = stdin.lock().lines()
        .map(|x| x.unwrap().parse().unwrap()).collect::<Vec<i32>>();

    for i in &v[1..] {
        solve(*i);
    }
}
