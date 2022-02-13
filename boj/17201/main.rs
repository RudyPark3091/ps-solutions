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

fn main() {
    read_string!();
    let s = read_string!();
    let mut ans = "Yes";
    for i in 1..s.len() {
        let ch = s.chars().nth(i).unwrap();
        let bef = s.chars().nth(i - 1).unwrap();
        if ch == bef {
            ans = "No";
            break;
        }
    }
    println!("{}", ans);
}
