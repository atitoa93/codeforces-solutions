// Problem: http://codeforces.com/contest/598
// Submission: http://codeforces.com/contest/598/submission/30763971

#include <bits/stdc++.h>
using namespace std;

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  int cases;
  scanf("%d", &cases);

  while (cases--) {
    long long n;
    scanf("%lld", &n);

    long long p = 1;
    while (p <= n) p <<= 1;

    printf("%lld\n", n * (n + 1) / 2 - 2 * (p - 1));
  }

  return 0;
}
