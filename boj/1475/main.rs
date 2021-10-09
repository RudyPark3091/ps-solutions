use std::io::{self, BufRead, Error};

fn main() -> Result<(), Error> {
    let stdin = io::stdin();
    let mut buf = String::new();

    stdin.lock().read_line(&mut buf)?;
    let x = buf.trim();
    let mut ans: Vec<i32> = vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

    for n in x.chars() {
        let idx: usize = n.to_string().parse().unwrap();
        ans[idx] += 1;
    }

    if (ans[6] + ans[9]) % 2 == 1 {
        ans[6] = (ans[6] + ans[9]) / 2 + 1;
    } else {
        ans[6] = (ans[6] + ans[9]) / 2;
    }

    ans[9] = ans[6];
    println!("{}", ans.iter().max().unwrap());

    Ok(())
}
