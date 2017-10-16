// Problem: http://codeforces.com/contest/609/problem/B
// Submission: http://codeforces.com/contest/609/submission/31434415

#include <bits/stdc++.h>
using namespace std;

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  int n, m;
  cin >> n >> m;

  vector <int> a(m + 1), c(m + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[x]++;
  }

  for (int i = 1; i <= m; ++i) {
    c[i] = a[i] + c[i - 1];
  }

  int ans = 0;

  for (int i = m; i > 0; --i) {
    ans += (c[i] - a[i]) * a[i];
  }

  cout << ans << endl;

  return 0;
}
