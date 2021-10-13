use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();

    let nm: Vec<usize> = buf.split_whitespace()
            .map(|x| x.parse().unwrap()).collect();
    let n = nm[0];
    let m = nm[1];
    let mut x = n;

    let mut arr = [0; 240_000];
    arr[x] = 1;
    loop {
        let d = d(x, m) as usize;
        if arr[d] > 1 { break; }
        arr[d] += 1;
        x = d;
    }

    let ans = arr.iter().filter(|&&x| x == 1).count();
    println!("{}", ans);
}

fn d(x: usize, n: usize) -> i32 {
    let mut sum = 0;
    for i in x.to_string().chars() {
        let m = i.to_digit(10).unwrap() as i32;
        sum += m.pow(n as u32);
    }
    sum
}
