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
        let l = s.len() / 2;
        let doit = s.chars().nth(l) == s.chars().nth(l - 1);
        println!( "{}", if doit { "Do-it" } else { "Do-it-Not" });
    }
}
