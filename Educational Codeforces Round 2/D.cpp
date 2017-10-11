// Problem: http://codeforces.com/contest/600/problem/D
// Sumission: http://codeforces.com/contest/600/submission/31228651

#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

typedef long double ld;

inline ld sq(ld a) { return a * a; };

ld partialArea(ld r1, ld r2, ld d) {
  ld alpha = acos((sq(r2) + sq(d) - sq(r1)) / (2 * d * r2));
  ld sArea = sq(r2) * alpha;
  ld tArea = sq(r2) * sin(alpha) * cos(alpha);
  return sArea - tArea;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  int x1, y1, r1;
  scanf("%d %d %d", &x1, &y1, &r1);

  int x2, y2, r2;
  scanf("%d %d %d", &x2, &y2, &r2);

  if (r1 < r2) {
    swap(x1, x2), swap(y1, y2), swap(r1, r2);
  }

  ld d = hypot(ld(x1 - x2), ld(y1 - y2));

  cout << setprecision(20);

  if (sq(r1) + sq(r2) + 2ll * r1 * r2 <= sq(x1 - x2) + sq(y1 - y2)) {
    cout << 0 << endl;
  } else if (sq(x1 - x2) + sq(y1 - y2) <= sq(r1) + sq(r2) - 2ll * r1 * r2) {
    cout << sq(r2) * PI << endl;
  } else {
    cout << partialArea(r1, r2, d) + partialArea(r2, r1, d) << endl;
  }

  return 0;
}
