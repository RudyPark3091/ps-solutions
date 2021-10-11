use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let v: Vec<String> = stdin.lock().lines().skip(1).map(|x| x.unwrap()).collect();
    let v: Vec<i32> = v[0].split_whitespace().map(|x| x.parse().unwrap()).collect();

    let mut ans = 0;
    let mut vv = [false; 101];
    for i in v {
        if vv[i as usize] { ans += 1; }
        else { vv[i as usize] = true; }
    }
    println!("{}", ans);
}
