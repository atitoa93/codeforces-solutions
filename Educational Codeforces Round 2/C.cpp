// Problem: http://codeforces.com/contest/600/problem/C
// Submission: http://codeforces.com/contest/600/submission/31180438

#include <bits/stdc++.h>
using namespace std;

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  string s, t;
  cin >> s;

  int freq[26] = {};
  for (int i = 0; i < s.size(); ++i) {
    ++freq[s[i] - 'a'];
  }

  vector <int> odds;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] % 2) {
      odds.push_back(i);
    }
  }

  for (int i = 0; i < odds.size() / 2; ++i) {
    ++freq[odds[i]];
    --freq[odds[odds.size() - i - 1]];
  }

  s = t = "";
  for (int i = 0; i < 26; ++i) {
    if (freq[i] % 2) {
      t += ('a' + i);
      --freq[i];
    }
    while (freq[i]) {
      s += ('a' + i);
      freq[i] -= 2;
    }
  }

  cout << s << t;
  reverse(s.begin(), s.end());
  cout << s << endl;

  return 0;
}
