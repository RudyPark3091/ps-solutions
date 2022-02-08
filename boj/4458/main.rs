use std::io::{self, BufRead};

macro_rules! read_lines {
    () => {{
        let stdin = io::stdin();
        stdin
            .lock()
            .lines()
            .map(|x| x.unwrap())
            .collect::<Vec<String>>()
    }};
}

fn main() {
    let lines = read_lines!();
    for line in &lines[1..] {
        println!(
            "{}{}",
            String::from(line.chars().nth(0).unwrap()).to_uppercase(),
            &line[1..]
        );
    }
}
