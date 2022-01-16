use std::io::{self, BufRead};
use std::iter::repeat;

fn pad(x: char, amt: usize) -> String {
    if amt == 0 {
        return x.to_string();
    }
    let mut s = repeat('0').take(amt).collect::<String>();
    s.push(x);
    return s.chars().rev().collect::<String>();
}

fn solve(x: String) {
    let mut ans: Vec<String> = Vec::new();
    for (i, c) in x.chars().rev().enumerate() {
        if c != '0' {
            let s = pad(c, i);
            ans.push(s);
        }
    }
    println!("{}\n{}", ans.len(), ans.join(" "));
}

fn main() {
    let stdin = io::stdin();
    let v = stdin
        .lock()
        .lines()
        .skip(1)
        .map(|x| x.unwrap())
        .collect::<Vec<String>>();
    for x in v {
        solve(x);
    }
}
