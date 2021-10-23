/// ./main.cpp과 같은 로직으로 작성되었지만 RTE를 받음
use std::io::{self, BufRead};
use std::cmp::{min, max};

fn main() {
    let stdin = io::stdin();
    let pairs = stdin
        .lock()
        .lines()
        .skip(1)
        .map(|l| {
            l.unwrap()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect::<Vec<i32>>()
        })
        .collect::<Vec<Vec<i32>>>();
    let mut arr = [0; 1002];
    let mut arr2 = [0; 1002];
    let mut arr3 = [0; 1002];

    for pair in pairs {
        let x = pair[0];
        let h = pair[1];
        arr[x as usize] = h;
    }

    let mut ans = 0;
    let mut _max = 0;

    for i in 0..1001 {
        _max = max(arr[i], _max);
        arr2[i] = _max;
    }
    _max = 0;
    for i in (0..1001).rev() {
        _max = max(arr[i], _max);
        arr3[i] = _max;
    }
    for i in 0..1001 {
        ans += min(arr2[i], arr3[i]);
    }
    println!("{}", ans);
}
