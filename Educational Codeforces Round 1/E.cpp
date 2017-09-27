// Problem: http://codeforces.com/contest/598/problem/E
// Submission: http://codeforces.com/contest/598/submission/30791247

#include <bits/stdc++.h>
using namespace std;

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  int dp[31][31][51];

  for (int n = 0; n < 31; ++n) {
    for (int m = 0; m < 31; ++m) {
      for (int k = 0; k < 51; ++k) {
        dp[n][m][k] = 1e9;
        if (!k || n * m == k) dp[n][m][k] = 0;
        for (int i = 0; i < k; ++i) {
          for (int j = 1; j < n; ++j) {
            dp[n][m][k] = min(dp[n][m][k], m * m + dp[j][m][i] + dp[n - j][m][k - i]);
          }
          for (int j = 1; j < m; ++j) {
            dp[n][m][k] = min(dp[n][m][k], n * n + dp[n][j][i] + dp[n][m - j][k - i]);
          }
        }
      }
    }
  }

  int cases;
  scanf("%d", &cases);

  int n, m, k;
  while(cases--) {
    scanf("%d %d %d", &n, &m, &k);

    printf("%d\n", dp[n][m][k]);
  }

  return 0;
}
