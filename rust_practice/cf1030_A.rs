//thanks tuna_salad for this template
use std::io::*;
use std::str::{self,*};
use std::fmt::Debug;
#[allow(unused_imports)] use std::cmp::Ordering::{self,*};
#[allow(unused_imports)] use std::ops::{self,*};
#[allow(unused_imports)] use std::iter::{self,*};
#[allow(unused_imports)] use std::collections::*;
#[allow(unused_macros)]
macro_rules! m {
  ($c:tt, $x:expr, $y:expr) => {{
    let b = $y; let a = &mut $x;
    if b $c *a { *a = b; true } else { false }
  }};
}
#[allow(unused_macros)]
macro_rules! l {
  ($($v:ident),* = $i:ident.$f:ident $a:tt) => {
    $( let $v = $i.$f$a; )*
  };
  ($($v:ident),*:$t:ty = $i:ident.$f:ident $a:tt) => {
    $( let $v:$t = $i.$f$a; )*
  };
}
struct WordReader<'a> { it : SplitAsciiWhitespace<'a> }
#[allow(dead_code)]
impl<'a> WordReader<'a> {
  fn new<T: Read>(b: &mut String, mut r: T) -> WordReader {
    b.clear();
    r.read_to_string(b).ok();
    WordReader { it: b.split_ascii_whitespace() }
  }
  fn from_stdin(b: &mut String) -> WordReader {
    WordReader::new(b, stdin())
  }
  fn sl(&mut self) ->  &str { self.it.next().unwrap() }
  fn bs(&mut self) -> &[u8] { self.sl().as_bytes()    }
  fn s(&mut self) -> String { String::from(self.sl()) }
  fn i(&mut self) ->    i32 { self.p()                }
  fn f(&mut self) ->    f64 { self.p()                }
  fn u(&mut self) ->  usize { self.p()                }
  fn sk(&mut self, n: usize) { self.it.nth(n - 1); }
  fn ii(&mut self, n: usize) -> impl Iterator<Item=i32> {
    self.ip(n).into_iter()
  }
  fn vi(&mut self, n: usize) -> Vec<i32> {
    self.vp::<i32>(n)
  }
  fn p<T: FromStr>(&mut self) -> T where T::Err: Debug {
    self.sl().parse::<T>().unwrap()
  }
  fn ip<T: FromStr>(&mut self, n: usize) -> impl Iterator<Item=T> where T::Err: Debug {
    self.vp(n).into_iter()
  }
  fn vp<T: FromStr>(&mut self, n: usize) -> Vec<T> where T::Err: Debug {
    (0..n).map(|_| self.p()).collect()
  }
}
//------------------- End rusT

fn main() {
  let mut bin = String::new();
  let mut input = WordReader::from_stdin(&mut bin);
  let n = input.i();
  let mut check : bool = false;
  for _ in 0..n {
    let v = input.i();
    check = if v == 1 { true } else { check };
  }
  println!("{}", if check { "hard" } else { "easy" });
}