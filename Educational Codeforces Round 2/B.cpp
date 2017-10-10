// Problem: http://codeforces.com/contest/600/problem/B
// Submission: http://codeforces.com/contest/600/submission/31179580

#include <bits/stdc++.h>
using namespace std;

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  int n, m;
  scanf("%d %d", &n, &m);

  int a[200000];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n);

  for (int i = 0; i < m; ++i) {
    int b;
    scanf("%d", &b);

    printf("%d ", upper_bound(a, a + n, b) - a);
  }

  return 0;
}
