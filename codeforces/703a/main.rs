use std::io::{self, BufRead};

fn f(s: &String, i: usize) -> u32 {
    s.chars().nth(i).unwrap().to_digit(10).unwrap()
}

fn main() {
    let stdin = io::stdin();
    let v = stdin.lock().lines().skip(1)
        .map(|x| x.unwrap()).collect::<Vec<String>>();
    let mut ans = (0, 0);
    for s in v.into_iter() {
        let a = f(&s, 0);
        let b = f(&s, 2);

        if a > b {
            ans.0 += 1;
        } else if a < b {
            ans.1 += 1;
        }
    }

    let s = if ans.0 > ans.1 {
        "Mishka"
    } else if ans.0 < ans.1 {
        "Chris"
    } else {
        "Friendship is magic!^^"
    };

    println!("{}", s);
}
