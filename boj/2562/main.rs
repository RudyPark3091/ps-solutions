use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let v: Vec<u8> = stdin.lock().lines()
        .map(|x| x.unwrap().parse().unwrap()).collect();
    let mut max = 0;
    let mut ans = 0;
    v.iter().enumerate().for_each(|(i, x)| {
        if *x > max {
            max = *x;
            ans = i + 1;
        }
    });
    println!("{}\n{}", max, ans);
}
