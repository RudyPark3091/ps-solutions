use std::io::{self, BufRead};

fn main() {
    let mut buf = String::new();
    let stdin = io::stdin();

    stdin.lock().read_line(&mut buf);
    let x: i32 = buf.trim().parse().unwrap();

    for i in 1..10 {
        println!("{} * {} = {}", x, i, x * i);
    }
}
