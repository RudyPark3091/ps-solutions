use std::io::{self, BufRead};

fn solve() {
    let stdin = io::stdin();
    let mut buf = String::new();
    for _ in 0..9 {
        stdin.lock().read_line(&mut buf).unwrap();
    }
    let v = buf
        .trim()
        .split("\n")
        .map(|x| {
            x.to_string()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect::<Vec<i32>>()
        })
        .collect::<Vec<Vec<i32>>>();
    let yonsei = &v.iter().fold(0, |acc, x| acc + x[0]);
    let korea = &v.iter().fold(0, |acc, x| acc + x[1]);

    if yonsei > korea {
        println!("Yonsei");
    } else if yonsei < korea {
        println!("Korea");
    } else {
        println!("Draw");
    }
}

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();
    let t = buf.trim().parse().unwrap();

    for _ in 0..t {
        solve();
    }
}
