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
    let s = read_string!();
    let c = s.chars().nth(0).unwrap();
    let mut flag = false;
    let mut ans = 0;

    for ch in s.chars().skip(1) {
        if flag && ch != c {
            continue;
        } else if ch != c {
            flag = true;
            ans += 1;
            continue;
        }
        flag = false;
    }
    println!("{}", ans);
}
