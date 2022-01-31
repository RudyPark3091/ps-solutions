use std::io::{self, BufRead};
use std::collections::HashMap;

macro_rules! read_lines {
    () => {{
        let stdin = io::stdin();
        stdin.lock().lines().skip(1).map(|x| x.unwrap()).collect()
    }};
}

fn main() {
    let v: Vec<String> = read_lines!();
    let mut hm = HashMap::new();

    for item in v {
        let item = hm.entry(item).or_insert(0);
        *item += 1;
    }

    let mut v: Vec<(String, i32)> = Vec::new();
    for item in hm {
        v.push(item);
    }

    v.sort_by(|a, b| a.0.cmp(&b.0));
    let mut mx = 0;
    let ans = v.iter().fold(String::new(), |acc, x| {
        if mx < x.1 {
            mx = x.1;
            x.0.clone()
        } else {
            acc
        }
    });
    println!("{}", ans);
}
