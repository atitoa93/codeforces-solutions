// Problem: http://codeforces.com/contest/598/problem/B
// Submission: http://codeforces.com/contest/598/submission/30766960

#include <bits/stdc++.h>
using namespace std;

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  char s[10000];
  scanf("%s", s);

  int m;
  scanf("%d", &m);

  while (m--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);

    rotate(s + l - 1, s + r - k % (r - l + 1), s + r);
  }

  printf("%s\n", s);

  return 0;
}
