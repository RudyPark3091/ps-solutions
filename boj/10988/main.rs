fn main() {
    let mut yes = true;
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf);
    for (i, c) in buf.trim().chars().enumerate() {
        let l = buf.len() - 2;
        if c != buf.chars().nth(l - i).unwrap() {
            yes = false;
            break;
        }
    }
    println!("{}", if yes { 1 } else { 0 });
}
