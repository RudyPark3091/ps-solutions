use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let v: Vec<usize> = stdin.lock().lines()
        .map(|x| x.unwrap().parse().unwrap()).collect();
    let l = v[4];
    let mut vv = vec![true; l];

    v.into_iter().take(4).for_each(|x| {
        for i in 1..=l / x {
            vv[x * i - 1] = false;
        }
    });

    let ans = vv.iter().filter(|x| !**x).count();
    println!("{}", ans);
}
