#include <iostream>
using namespace std;

int  n, m;
string s1[11];
string s2[11];

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s2[i];
  }
}

bool check() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool same = s1[i][j] == s2[i][2 * j] && s1[i][j] == s2[i][2 * j + 1];
      if (!same) return false;
    }
  }
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  input();
  cout << (check() ? "Eyfa" : "Not Eyfa") << '\n';
  return 0;
}
