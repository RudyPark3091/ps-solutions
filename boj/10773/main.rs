use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let v = stdin
        .lock()
        .lines()
        .skip(1)
        .map(|x| x.unwrap().parse().unwrap())
        .collect::<Vec<i32>>();
    let mut s = vec![];
    v.iter().for_each(|x| {
        if *x == 0 {
            s.pop();
        } else {
            s.push(*x);
        }
    });
    let sum: i32 = s.iter().sum();
    println!("{}", sum);
}
