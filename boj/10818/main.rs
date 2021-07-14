use std::io;
use std::io::BufRead;

fn main() {
    let stdin = io::stdin();
    let v = stdin.lock().lines().skip(1)
        .map(|x| x.unwrap()).collect::<Vec<String>>();
    let v = v[0].split_whitespace()
        .map(|x| x.parse().unwrap()).collect::<Vec<i32>>();
    let mut min = 1000000;
    let mut max = -1000000;
    v.iter().for_each(|x| {
        if *x > max {
            max = *x;
        }
        if *x < min {
            min = *x;
        }
    });
    println!("{} {}", min, max);
}
