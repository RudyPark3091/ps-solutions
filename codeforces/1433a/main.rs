use std::io::{self, BufRead};

fn read_int(stdin: &io::Stdin) -> i32 {
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();
    let s = buf.trim();
    let n: i32 = s.parse().unwrap();
    n
}

fn solve(n: i32) -> i32 {
    let base = [1, 11, 111, 1111];
    let mut ans = 0;
    for i in 1..10 {
        for j in 0..4 {
            let num = base[j] * i;
            ans += (j + 1) as i32;
            if num == n {
                return ans;
            }
        }
    }
    return -1;
}

fn main() {
    let stdin = io::stdin();
    let t = read_int(&stdin);
    for _ in 0..t {
        let n = read_int(&stdin);
        let ans = solve(n);
        println!("{}", ans);
    }
}
