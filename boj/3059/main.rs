use std::io::{self, BufRead};

macro_rules! read_string {
    () => {{
        let stdin = io::stdin();
        let mut buf = String::new();
        stdin.lock().read_line(&mut buf).unwrap();
        buf.truncate(buf.len() - 1);
        buf
    }};
}

macro_rules! read_int {
    () => {{
        let s = read_string!();
        let n: i32 = s.parse().unwrap();
        n
    }};
}

fn main() {
    let n = read_int!();
    for _ in 0..n {
        let s = read_string!();
        let mut arr = [false; 26];
        for ch in s.chars() {
            let idx = ch as usize;
            arr[idx - 65] = true;
        }

        let mut ans = 0;
        for i in 0..26 {
            if !arr[i] {
                ans += i + 65;
            }
        }
        println!("{}", ans);
    }
}
