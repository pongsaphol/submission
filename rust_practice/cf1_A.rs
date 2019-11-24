use std::io;

fn main() {
  let mut s = String::new();
  io::stdin().read_line(&mut s).unwrap();
  let v = s.split_whitespace().map(|a| a.parse().unwrap()).collect::<Vec<i64>>();
  let n = v.get(0).unwrap();
  let m = v.get(1).unwrap();
  let a = v.get(2).unwrap();
  println!("{}", ((n + a - 1) / a) * ((m + a - 1) / a));
}