#include <iostream>
using namespace std;

int n;
string pattern;
string v[50];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
}

void solve() {
  pattern = v[0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (pattern[j] != v[i][j]) { pattern[j] = '?'; }
    }
  }
  cout << pattern << '\n';
}

int main() {
  input();
  solve();
  return 0;
}
