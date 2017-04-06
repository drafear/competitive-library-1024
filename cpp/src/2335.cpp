#include "../include/math/mod.cpp"

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  Mod res = 0;
  for (int i = 0; i <= k; i++) {
    int j = k - i;
    Mod y = comb(n + 2 * i, i) - comb(n + 2 * i, i - 1);
    Mod x = comb(m + 2 * j, j) - comb(m + 2 * j, j - 1);
    Mod c = comb(n + m + k * 2, n + i * 2);
    res = res + y * x * c;
  }
  cout << int(res) << endl;
  return 0;
}
