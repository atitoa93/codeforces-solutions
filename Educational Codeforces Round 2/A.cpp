// Problem: http://codeforces.com/contest/600/problem/A
// Submission: http://codeforces.com/contest/600/submission/31179487

#include <bits/stdc++.h>
using namespace std;

struct parser {
  int idx;
  string s;

  parser() {
    idx = 0;
    s = "";
  }

  parser(string _s) {
    idx = 0;
    s = _s;
  }

  bool get(string &ret) {
    ret = "";

    if (idx > s.size()) {
      return false;
    }

    if (idx == s.size()) {
      if (s.back() == ',' || s.back() == ';') {
        ++idx;
        return true;
      }
      return false;
    }

    while (idx < s.size()) {
      if (s[idx] == ',' || s[idx] == ';') {
        ++idx;
        break;
      }
      ret += s[idx];
      ++idx;
    }

    return true;
  }

  bool isNumber(string &str) {
    for (int i = 0; i < str.size(); ++i) {
      if (!isdigit(str[i])) {
        return false;
      }
    }
    return str.size() && (str.size() == 1 || str[0] != '0');
  }
};


void print(string s) {
  if (s != "") {
    s.back() = '"';
    cout << "\"" << s << endl;
  } else {
    cout << "-" << endl;
  }
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen(".i", "r", stdin);
    freopen(".o", "w", stdout);
  #endif

  string str;
  cin >> str;

  parser p(str);

  string word, f = "", s = "";
  while (p.get(word)) {
    if (p.isNumber(word)) {
      f += word + ',';
    } else {
      s += word + ',';
    }
  }

  print(f);
  print(s);

  return 0;
}
