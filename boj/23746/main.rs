use std::collections::HashMap;
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
    let mut map = HashMap::new();

    for _ in 0..n {
        let s = read_string!();
        let v = s
            .split_whitespace()
            .map(|x| x.to_string())
            .collect::<Vec<String>>();
        map.insert(v[1].clone(), v[0].clone());
    }

    let st = read_string!();
    let se = read_string!()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect::<Vec<i32>>();
    let full = st
        .chars()
        .map(|x| map.get(&x.to_string()).unwrap())
        .map(|x| x.clone())
        .collect::<String>();
    let ans = full.chars()
        .skip((se[0] - 1) as usize)
        .take((se[1] - se[0]) as usize + 1)
        .collect::<String>();
    println!("{}", ans);
}
