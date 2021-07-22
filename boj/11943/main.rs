use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let v = stdin
        .lock()
        .lines()
        .map(|x| {
            x.unwrap()
                .split_whitespace()
                .map(|y| y.parse().unwrap())
                .collect::<Vec<i32>>()
        })
        .collect::<Vec<_>>();

    let a = v[0][0];
    let b = v[0][1];

    let c = v[1][0];
    let d = v[1][1];

    let ans = (a + d).min(b + c);

    println!("{}", ans);
}
