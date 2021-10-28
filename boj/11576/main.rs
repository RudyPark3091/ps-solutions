use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();
    stdin.lock().read_line(&mut buf).unwrap();
    stdin.lock().read_line(&mut buf).unwrap();
    let v = buf.split_whitespace()
        .map(|x| x.parse().unwrap()).collect::<Vec<i32>>();
    let (a, b, _) = (v[0], v[1], v[2]);
    let base = v.into_iter().skip(3).collect::<Vec<i32>>();

    let ans = to_dec(&base, a, b);
    for c in ans.into_iter().rev() {
        print!("{} ", c);
    }
    println!("");
}

fn to_dec(xs: &Vec<i32>, a: i32, b: i32) -> Vec<i32> {
    let l = xs.len() as u32;
    let mut decm = 0;
    for (i, x) in xs.into_iter().enumerate() {
        decm += x * a.pow(l - i as u32 - 1);
    }

    let mut ret = Vec::new();
    while decm > 0 {
        let val = decm % b;
        ret.push(val);
        decm /= b;
    }
    ret
}
