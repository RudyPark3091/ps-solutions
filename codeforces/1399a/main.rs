use std::io;

fn input() -> Vec<i32> {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin.read_line(&mut buf).unwrap();
    buf.clear();
    stdin.read_line(&mut buf).unwrap();

    buf.split_whitespace().map(|x| x.parse().unwrap()).collect()
}

fn solve(v: Vec<i32>) {
    for i in 1..v.len() {
        let a = v[i - 1];
        let b = v[i];
        if b - a > 1 {
            println!("NO");
            return;
        }
    }
    println!("YES");
}

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.read_line(&mut buf).unwrap();
    let n = buf.trim().parse::<i32>().unwrap();

    for _ in 0..n {
        let mut v = input();
        v.sort_by(|a, b| a.cmp(b));
        solve(v);
    }
}
