// Problem: http://codeforces.com/contest/609/problem/A
// Submission: http://codeforces.com/contest/609/submission/31434287

#include <bits/stdc++.h>
using namespace std;

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  int n, m;
  cin >> n >> m;

  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = a.size() - 1; i >= 0; --i) {
    ++ans;
    m -= a[i];
    if (m <= 0) {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
