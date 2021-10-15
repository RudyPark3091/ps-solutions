use std::io::{self, BufRead};
use std::iter::repeat;

fn main() {
    let stdin = io::stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf).unwrap();

    let x = buf
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect::<Vec<i32>>();
    let s = x[0];
    let n = x[1].to_string();

    let mut v: Vec<String> = Vec::new();

    for i in 0 .. 2 * s + 3 {
        v.push(String::new());
        for c in n.chars() {
            v[i as usize].push_str(&segment(c, i as usize, (2 * s + 3) as usize));
            // println!("{:?}, {:?}", i, c);
        }
        println!("{}", v[i as usize]);
    }
}

fn hor(n: usize) -> String {
    let n = (n - 3) / 2;
    format!(" {}  ", repeat('-').take(n).collect::<String>())
}

fn empty_hor(n: usize) -> String {
    let n = (n - 3) / 2;
    repeat(' ').take(n + 3).collect::<String>()
}

fn vert_first(n: usize) -> String {
    let n = (n - 3) / 2;
    format!("|{} ", repeat(' ').take(n + 1).collect::<String>())
}

fn vert_last(n: usize) -> String {
    let n = (n - 3) / 2;
    format!("{}| ", repeat(' ').take(n + 1).collect::<String>())
}

fn vert_both(n: usize) -> String {
    let n = (n - 3) / 2;
    format!("|{}| ", repeat(' ').take(n).collect::<String>())
}

fn segment(c: char, i: usize, s: usize) -> String {
    match c {
        '1' => match i {
            x if is_hor(x, s) => empty_hor(s),
            _ => vert_last(s),
        },
        '2' => match i {
            x if is_hor(x, s) => hor(s),
            x if x < s / 2 => vert_last(s),
            _ => vert_first(s),
        }
        '3' => match i {
            x if is_hor(x, s) => hor(s),
            _ => vert_last(s),
        },
        '4' => match i {
            x if x == 0 || x == s - 1 => empty_hor(s),
            x if x == s / 2 => hor(s),
            x if x < s / 2 => vert_both(s),
            _ => vert_last(s),
        },
        '5' => match i {
            x if is_hor(x, s) => hor(s),
            x if x < s / 2 => vert_first(s),
            _ => vert_last(s),
        },
        '6' => match i {
            x if is_hor(x, s) => hor(s),
            x if x < s / 2 => vert_first(s),
            _ => vert_both(s),
        },
        '7' => match i {
            x if x == 0 => hor(s),
            x if x == s / 2 || x == s - 1 => empty_hor(s),
            _ => vert_last(s),
        },
        '8' => match i {
            x if is_hor(x, s) => hor(s),
            _ => vert_both(s),
        },
        '9' => match i {
            x if is_hor(x, s) => hor(s),
            x if x < s / 2 => vert_both(s),
            _ => vert_last(s),
        },
        '0' => match i {
            x if x == 0 || x == s - 1 => hor(s),
            x if x == s / 2 => empty_hor(s),
            _ => vert_both(s),
        },
        _ => String::new(),
    }
}

fn is_hor(n: usize, s: usize) -> bool {
    match n {
        x if x == s / 2 || x == 0 || x == s - 1 => true,
        _ => false,
    }
}
