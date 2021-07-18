use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin.lock().read_line(&mut buf);
    stdin.lock().read_line(&mut buf);
    let arr = buf
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect::<Vec<i32>>();

    let t = arr[1];
    let mut sum = 0;
    let mut fin = false;
    for (i, num) in arr.iter().skip(2).enumerate() {
        sum += num;
        if sum > t {
            println!("{}", i);
            fin = true;
            break;
        }
    }

    if !fin {
        println!("{}", arr.len() - 2);
    }
}
