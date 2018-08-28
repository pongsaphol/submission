public class xylophone {
  public void solve(int N) {
    int x = xylophone_lib.query(1, N);
    for (int i = 1; i <= N; ++i) {
      xylophone_lib.answer(i, i);
    }
  }
}
