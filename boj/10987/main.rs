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
    let cnt = s.chars().filter(|&x| {
        x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'
    }).count();
    println!("{}", cnt);
}
