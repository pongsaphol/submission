use std::io;

fn main() {
  let mut s = String::new();
  io::stdin().read_line(&mut s).unwrap();
  let v : i32 = s.trim().parse().unwrap();
  println!("{}", if v >= 4 && v % 2 == 0 { "YES" } else { "NO" });
}