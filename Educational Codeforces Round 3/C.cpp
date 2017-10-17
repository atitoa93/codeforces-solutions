// Problem: http://codeforces.com/contest/609/problem/C
// Submission: http://codeforces.com/contest/609/submission/31436414

#include <bits/stdc++.h>
using namespace std;

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  int n;
  cin >> n;

  int sum = 0;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  sort(a.begin(), a.end());

  int d = sum / n, ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += abs(a[i] - d - (i >= (n - (sum % n))));
  }

  cout << ans / 2 << endl;

  return 0;
}
