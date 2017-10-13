// Problem: http://codeforces.com/contest/600/problem/E
// Submission: http://codeforces.com/contest/600/submission/31265356

#include <bits/stdc++.h>
using namespace std;

int c[100000];
int mx[100000];
long long ans[100000];
vector <vector <int> > adj;

void dfs(int u, int p, map <int, int> &cum) {
  ans[u] = c[u];
  cum[c[u]] = mx[u] = 1;

  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v == p) continue;

    map <int, int> childCum;
    dfs(v, u, childCum);

    int curMx = mx[u];
    long long curSum = ans[u];
    if (childCum.size() > cum.size()) {
      curMx = mx[v];
      curSum = ans[v];
      swap(childCum, cum);
    }

    for (pair <int, int> e : childCum) {
      int &colorCount = cum[e.first];
      colorCount += e.second;
      if (curMx == colorCount) {
        curSum += e.first;
      } else if (curMx < colorCount) {
        curMx = colorCount;
        curSum = e.first;
      }
    }
    mx[u] = curMx;
    ans[u] = curSum;
  }
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  adj.resize(n);

  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;

    --x, --y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  map <int, int> tmp;
  dfs(0, -1, tmp);

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }

  return 0;
}
