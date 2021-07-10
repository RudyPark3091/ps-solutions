use std::io;
use std::error::Error;
use io::{Read, Write};

fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();

    let mut input = stdin.lock();
    let mut output = io::BufWriter::new(stdout.lock());

    let mut buf = String::new();
    input.read_to_string(&mut buf).unwrap();

    let buf = buf.lines().skip(1);
    buf.for_each(|line| {
        let sum =
            line.split_whitespace()
            .map(|word| { word.parse::<i32>().unwrap() })
            .sum::<i32>();
        writeln!(output, "{}", sum).unwrap();
    });
}
