use std::io::{self, BufRead};
use std::cmp::min;

fn main() {
    let stdin = io::stdin();
    let v: Vec<String> = stdin.lock().lines().skip(1)
        .map(|x| x.unwrap()).collect();
    let v: Vec<i32> = v[0]
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let mut ans = 0;
    let n = v.len();

    for i in 1..n-1 {
        let left = &v[0..i].iter().max().unwrap();
        let right = &v[i..n].iter().max().unwrap();
        let x = *min(left, right) - v[i];
        ans += if x > 0 { x } else { 0 };
    }
    println!("{}", ans);
}
