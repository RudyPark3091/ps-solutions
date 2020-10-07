#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a, b;
vector<pair<int, int>> lines;
int dp[100] = { 1, };

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    lines.push_back({a, b});
  }
}

void solve() {
  sort(lines.begin(), lines.end());

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      if (lines[j].second < lines[i].second) {
        if (dp[j] > cnt) { cnt = dp[j]; }
      }
    }
    dp[i] = cnt + 1;
  }

  int max = 0;
  for (int i = 0; i < n; i++) {
    if (max < dp[i]) { max = dp[i]; }
  }
  cout << n - max << '\n';
}

int main() {
  input();
  solve();
}
