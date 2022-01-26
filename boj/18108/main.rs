use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();
    let n: i32 = buf.trim().parse().unwrap();
    println!("{:?}", n - 543);
}
