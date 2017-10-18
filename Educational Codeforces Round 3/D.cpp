// Problem: http://codeforces.com/contest/609/problem/D
// Submission: http://codeforces.com/contest/609/submission/31493504

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
const int INF = 2e9;

int n, m, k, s;
int idx1, idx2, day1, day2;
vector <pair <long long, int> > a, b, c[2];

bool solve(int mid) {
  long long mn1 = INF, mn2 = INF;
  for (int i = 0; i < mid; ++i) {
    if (mn1 > a[i].first) {
      day1 = a[i].second;
      mn1 = a[i].first;
    }
    if (mn2 > b[i].first) {
      day2 = b[i].second;
      mn2 = b[i].first;
    }
  }

  int sz1 = min((int)c[0].size(), k);
  int sz2 = min((int)c[1].size(), k);
  int rem = k - sz1;

  long long s1 = 0, s2 = 0;

  for (int i = 0; i < sz1; ++i) {
    s1 += c[0][i].first * mn1;
  }

  for (int i = 0; i < rem; ++i) {
    s2 += c[1][i].first * mn2;
  }

  idx1 = sz1, idx2 = rem;
  long long mn = s1 + s2;
  for (int i = 0; i < min(sz1, sz2 - rem); ++i) {
    s1 -= c[0][sz1 - i - 1].first * mn1;
    s2 += c[1][rem + i].first * mn2;
    if (mn > s1 + s2) {
      idx1 = sz1 - i - 1;
      idx2 = rem + i + 1;
      mn = s1 + s2;
    }
  }

  return mn <= s;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  cin >> n >> m >> k >> s;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a.push_back(make_pair(x, i + 1));
  }

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b.push_back(make_pair(x, i + 1));
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    c[x - 1].push_back(make_pair(y, i + 1));
  }

  sort(c[0].begin(), c[0].end());
  sort(c[1].begin(), c[1].end());

  int st = 1, ed = n;
  while (st < ed) {
    int mid = st + (ed - st) / 2;
    if (solve(mid)) ed = mid;
    else st = mid + 1;
  }

  if (solve(st)) {
    cout << st << endl;
    for (int i = 0; i < idx1; ++i) {
      cout << c[0][i].second << " " << day1 << endl;
    }
    for (int i = 0; i < idx2; ++i) {
      cout << c[1][i].second << " " << day2 << endl;
    }
  } else {
    cout << -1 << endl;
  }

  return 0;
}
