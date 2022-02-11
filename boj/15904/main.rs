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
    let xs = ['U', 'C', 'P', 'C'];
    let mut i = 0;
    for c in s.chars() {
        if i >= 4 { break; }
        if c == xs[i] { i += 1; }
    }
    println!("I {} UCPC", if i >= 4 { "love" } else { "hate" });
}
