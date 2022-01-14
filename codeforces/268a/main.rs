use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let v = stdin
        .lock()
        .lines()
        .skip(1)
        .map(|x| x.unwrap())
        .collect::<Vec<String>>();

    let v = v
        .into_iter()
        .map(|pair| {
            pair.split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect::<Vec<i32>>()
        })
        .collect::<Vec<Vec<i32>>>();

    let mut ans = 0;
    for i in 0..v.len() {
        for j in 0..v.len() {
            if v[i][0] == v[j][1] {
                ans += 1;
            }
        }
    }
    println!("{}", ans);
}
