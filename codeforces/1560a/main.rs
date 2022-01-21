use std::io::{self, BufRead};

fn end_three(num: i32) -> bool {
    let s = num.to_string();
    s.chars().nth(s.len() - 1).unwrap() == '3'
}

fn main() {
    let stdin = io::stdin();
    let v = stdin
        .lock()
        .lines()
        .skip(1)
        .map(|x| x.unwrap().parse().unwrap())
        .collect::<Vec<usize>>();
    let mut arr = [0; 1000];
    let mut num = 1;
    for i in 0..1000 {
        while num % 3 == 0 || end_three(num) {
            num += 1;
        }
        arr[i] = num;
        num += 1;
    }
    for item in v {
        println!("{}", arr[item - 1_usize]);
    }
}
