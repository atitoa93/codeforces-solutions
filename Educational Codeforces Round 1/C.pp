// Problem: http://codeforces.com/contest/598/problem/C
// Submission: http://codeforces.com/contest/598/submission/30782313

#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  int n;
  scanf("%d", &n);

  pair <long double, int> a[100000];

  int x, y;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x, &y);

    a[i] = make_pair(atan2(y, x), i + 1);

    if (a[i].first < 0) a[i].first += 2 * PI;
  }

  sort(a, a + n);

  x = a[0].second, y = a[n - 1].second;
  long double mn = 2 * PI - a[n - 1].first + a[0].first;
  for (int i = 1; i < n; ++i) {
    if (a[i].first - a[i - 1].first < mn) {
      mn = a[i].first - a[i - 1].first;
      x = a[i].second, y = a[i - 1].second;
    }
  }

  printf("%d %d\n", x, y);

  return 0;
}
