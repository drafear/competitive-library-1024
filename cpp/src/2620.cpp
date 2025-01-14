#include "../include/graph/bfs01.cpp"

#define REP(i,n) for(int i=0;i<(n);++i)

int ri[512][512], dw[512][512];
char str[1024];

int main() {
  int H, W, N, sx, sy, gx, gy;
  scanf("%d%d%d", &W, &H, &N);
  scanf("%d%d%d%d", &sx, &sy, &gx, &gy);
  REP(i,N) {
    int x, y, t;
    scanf("%d%d%d%s", &x, &y, &t, str);
    REP(j,t) {
      int len = strlen(str);
      for (int k = 0; k < len; ++k) {
        char c = str[k];
        if (c == 'U' && y > 0) { ++ri[y][x]; --y; }
        else if (c == 'D' && y < H-1) { ++y; ++ri[y][x]; }
        else if (c == 'L' && x > 0) { ++dw[y][x]; --x; }
        else if (c == 'R' && x < W-1) { ++x; ++dw[y][x]; }
      }
    }
  }
  Graph<int> g((H + 1) * (W + 1));
  REP(i,H+1) REP(j,W) add_edge(g, i*(W+1)+j, i*(W+1)+j+1, ri[i][j]);
  REP(i,H) REP(j,W+1) add_edge(g, i*(W+1)+j, (i+1)*(W+1)+j, dw[i][j]);
  REP(i,H+1) REP(j,W) add_edge(g, i*(W+1)+j+1, i*(W+1)+j, ri[i][j]);
  REP(i,H) REP(j,W+1) add_edge(g, (i+1)*(W+1)+j, i*(W+1)+j, dw[i][j]);
  vector<int> d = bfs01(g, sy*(W+1)+sx);
  printf("%d\n", d[gy*(W+1)+gx]);
  return 0;
}
