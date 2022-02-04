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

macro_rules! read_int {
    () => {{
        let s = read_string!();
        let n: i32 = s.parse().unwrap();
        n
    }};
}

fn solve(s: String) -> i32 {
    let mut ret = 0;
    for ch in s.chars() {
        if ch == ' ' {
            continue;
        }
        ret += (ch as i32) - 64;
    }
    return ret;
}

fn main() {
    let n = read_int!();
    for _ in 0..n {
        let s = read_string!();
        let score = solve(s);
        if score == 100 {
            println!("PERFECT LIFE");
        } else {
            println!("{}", score);
        }
    }
}
