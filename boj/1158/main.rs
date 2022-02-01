use std::io::{self, BufRead};
use std::collections::VecDeque;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();

    let v: Vec<i32> = buf.split_whitespace()
        .map(|x| x.parse().unwrap()).collect();
    let n = v[0] as usize;
    let k = v[1] as usize;

    let mut ans = Vec::new();
    let mut q = VecDeque::new();
    for i in 1..=n {
        q.push_back(i);
    }

    let mut idx = 0;
    while q.len() > 0 {
        let item = q.pop_front().unwrap();
        if idx % k == k - 1 {
            ans.push(item);
            idx = 0;
            continue;
        }
        q.push_back(item);
        idx += 1;
    }
    print!("<");
    for i in 0..ans.len() - 1 {
        print!("{}, ", ans[i]);
    }
    println!("{}>", ans[ans.len() - 1]);
}
