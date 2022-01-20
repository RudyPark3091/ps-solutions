use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();
    buf.clear();
    stdin.lock().read_line(&mut buf).unwrap();
    let v = buf
        .split_whitespace()
        .enumerate()
        .map(|(i, x)| (i + 1usize, x.parse().unwrap()))
        .collect::<Vec<(usize, i32)>>();

    let ones = &v[..]
        .into_iter()
        .filter(|x| x.1 == 1)
        .collect::<Vec<&(usize, i32)>>();
    let twos = &v[..]
        .into_iter()
        .filter(|x| x.1 == 2)
        .collect::<Vec<&(usize, i32)>>();
    let threes = &v[..]
        .into_iter()
        .filter(|x| x.1 == 3)
        .collect::<Vec<&(usize, i32)>>();

    let x = [ones.len(), twos.len(), threes.len()];
    let x = x.iter().min().unwrap();
    println!("{}", x);
    for i in 0..*x {
        println!("{} {} {}", ones[i].0, twos[i].0, threes[i].0);
    }
}
