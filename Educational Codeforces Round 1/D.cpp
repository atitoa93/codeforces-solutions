// Problem: http://codeforces.com/contest/598/problem/D
// Submission: http://codeforces.com/contest/598/submission/30786083

#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char g[1000][1000];
int vis[1000][1000];

int n, m, k;

void dfs(int x, int y) {
  vis[x][y] = 0;
  for (int d = 0; d < 4; ++d) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (g[nx][ny] == '*') {
      vis[x][y] += 1;
    }
    else if (vis[nx][ny] == -1) {
      dfs(nx, ny);
      vis[x][y] += vis[nx][ny];
    }
  }
}

void populate(int x, int y, int v) {
  vis[x][y] = v;
  for (int d = 0; d < 4; ++d) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (vis[nx][ny] >= 0 && vis[nx][ny] < v) {
      populate(nx, ny, v);
    }
  }
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  scanf("%d %d %d", &n, &m, &k);

  for (int i = 0; i < n; ++i) {
    scanf("%s", g[i]);
  }

  memset(vis, -1, sizeof(vis));

  int x, y;
  while (k--) {
    scanf("%d %d", &x, &y);
    --x, --y;

    if (vis[x][y] == -1) {
      dfs(x, y);
      populate(x, y, vis[x][y]);
    }

    printf("%d\n", vis[x][y]);
  }

  return 0;
}
