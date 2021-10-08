use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();

    let x: i32 = buf.trim().parse().unwrap();
    let mut a = (x % 10) * 10 + (x / 10 + x % 10) % 10;
    let mut ans = 1;

    while a != x {
        a = (a % 10) * 10 + (a / 10 + a % 10) % 10;
        ans += 1;
    }
    println!("{}", ans);
}
