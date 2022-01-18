use std::io::{self, BufRead};

fn solve(s: String) -> String {
    let mut ret = String::new();
    let l: usize = (s.len() - 2) / 2;

    ret.push(s.chars().nth(0).unwrap());
    for i in 0..l {
        ret.push(s.chars().nth(1 + i * 2).unwrap());
    }
    ret.push(s.chars().last().unwrap());

    return ret;
}

fn main() {
    let stdin = io::stdin();
    let v = stdin
        .lock()
        .lines()
        .skip(1)
        .map(|x| x.unwrap())
        .collect::<Vec<String>>();
    v.into_iter()
        .map(|s| solve(s))
        .for_each(|s| println!("{}", s));
}
