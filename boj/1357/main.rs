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
    let ab = s
        .split_whitespace()
        .map(|x| x.chars().rev().collect::<String>())
        .collect::<Vec<String>>();
    let ans: i32 = (ab[0].parse::<i32>().unwrap()) + (ab[1].parse::<i32>().unwrap());
    let ans = ans
        .to_string()
        .chars()
        .rev()
        .collect::<String>()
        .parse::<i32>()
        .unwrap();
    println!("{}", ans);
}
