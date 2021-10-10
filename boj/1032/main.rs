use std::io::{self, BufRead};
use std::mem::take;
use std::str;

fn main() {
    let stdin = io::stdin();
    let v: Vec<String> = stdin
        .lock()
        .lines()
        .skip(1)
        .map(|x| x.unwrap())
        .collect::<Vec<String>>();

    let mut base = v[0].clone();
    let mut base = take(&mut base).into_bytes();

    for s in v.iter().skip(1) {
        for (i, c) in s.chars().enumerate() {
            if c != base[i] as char {
                base[i] = '?' as u8;
            }
        }
    }

    let ans = str::from_utf8(&base).unwrap();
    println!("{}", ans);
}
