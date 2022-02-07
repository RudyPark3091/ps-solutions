use std::io::{self, BufRead};

macro_rules! read_string {
    () => {{
        let stdin = io::stdin();
        let mut buf = String::new();
        stdin.lock().read_line(&mut buf).unwrap();
        buf.truncate(buf.len() - 1);
        if buf == "*" {
            None
        } else {
            Some(buf)
        }
    }};
}

fn main() {
    while let Some(s) = read_string!() {
        let s = s
            .split_whitespace()
            .map(|x| x.chars().nth(0).unwrap())
            .collect::<String>()
            .to_lowercase();

        if s.len() == 1 {
            println!("Y");
            continue;
        }

        for i in 1..s.len() {
            let ch = s.chars().nth(i).unwrap();
            if ch != s.chars().nth(0).unwrap() {
                println!("N");
                break;
            } else if i == s.len() - 1 {
                println!("Y");
            }
        }
    }
}
