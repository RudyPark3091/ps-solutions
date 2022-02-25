use std::io::{self, BufRead};

macro_rules! read_string {
    () => {{
        let stdin = io::stdin();
        let mut buf = String::new();
        stdin.lock().read_line(&mut buf).unwrap();
        buf.truncate(buf.len() - 1);
        buf
    }};
}

fn main() {
    let s = read_string!();
    let v = s
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect::<Vec<i32>>();
    let ans = if v[0] == v[1] && v[1] == v[2] {
        10000 + v[0] * 1000
    } else if v[0] == v[1] || v[1] == v[2] {
        1000 + v[1] * 100
    } else if v[0] == v[2] {
        1000 + v[0] * 100
    } else {
        v.iter().max().unwrap() * 100
    };
    println!("{}", ans);
}
