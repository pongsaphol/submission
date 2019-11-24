use std::io;

fn main() {
  let mut s = String::new();
  io::stdin().read_line(&mut s).unwrap();
  let mut v = s.split_whitespace().map(|a| a.parse::<i32>().unwrap());
  v.next().unwrap();
  let k = v.next().unwrap() as usize;
  s = String::new();
  io::stdin().read_line(&mut s).unwrap();
  let arr = s.split_whitespace().map(|a| a.parse::<i32>().unwrap());
  let mut c = 1;
  let mut sol = 0;

  for (i, x) in arr.enumerate() {
    if x > 0 && i < k {
      c = x;
    }
    if x >= c {
      sol += 1;
    }
  }
  println!("{}", sol);
}