use std::io::{self, BufRead};
use std::error::Error;

fn main() -> Result<(), Box<dyn Error>> {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf)?;
    let s: String = buf.trim().into();
    let mut max = divide_merge(&s, 0, 1);

    for i in 0..s.len() - 1 {
        for j in i + 1..s.len() - 1 {
            let result = divide_merge(&s, i, j);
            score(result, &mut max);
        }
    }
    println!("{}", max);
    Ok(())
}

fn divide_merge(s: &String, x: usize, y: usize) -> String {
    let mut _s = String::new();
    format!(
        "{}{}{}",
        reverse(&s[0 .. x + 1]),
        reverse(&s[x + 1 .. y + 1]),
        reverse(&s[y + 1 .. s.len()]),
    )
}

fn reverse(s: &str) -> String {
    s.chars().rev().collect::<String>()
}

fn score(s: String, m: &mut String) {
    let b = s.as_bytes();
    for (i, byte) in m.as_bytes().iter().enumerate() {
        if byte < &b[i] {
            break;
        } else if byte > &b[i] {
            *m = s;
            break;
        }
    }
}
