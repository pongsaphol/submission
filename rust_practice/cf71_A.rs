use std::io;

fn main() {
  let mut s = String::new();
  io::stdin().read_line(&mut s).unwrap();
  let n: i32 = s.trim().parse().unwrap();
  for _ in 0..n {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s = String::from(s.trim());
    let x = s.chars();
    if x.count() <= 10 {
      println!("{}", s);
    } else {
      let mut i = s.chars();
      let a = i.next().unwrap();
      let b = i.rev().next().unwrap();
      println!("{}{}{}", a, s.bytes().len() - 2, b);
    }
  }
}