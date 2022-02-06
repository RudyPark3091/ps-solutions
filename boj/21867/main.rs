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
    let ans = read_string!()
        .chars()
        .filter(|&x| x != 'J' && x != 'A' && x != 'V')
        .collect::<String>();
    let ans = if ans == "" {
        String::from("nojava")
    } else {
        ans
    };
    println!("{}", ans);
}
