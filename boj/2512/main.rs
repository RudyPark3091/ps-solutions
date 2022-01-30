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

fn solve(v: &Vec<i32>, m: i32) -> i32 {
    let mut left = 0;
    let mut right = v.iter().fold(0, |acc, &x| if acc > x { acc } else { x });
    let mut limit = m;

    while left <= right {
        let mid = (left + right) / 2;
        let sum: i32 = v.iter().map(|&x| if x > mid { mid } else { x }).sum();
        if sum <= m {
            left = mid + 1;
            limit = mid;
        } else if sum > m {
            right = mid - 1;
        }
    }

    return limit;
}

fn main() {
    let _ = read_string!();
    let v: Vec<i32> = read_string!()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    let m = read_int!();

    let ans = solve(&v, m);
    println!("{}", ans);
}
