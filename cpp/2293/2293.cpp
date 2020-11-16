#include <iostream>
using namespace std;

int n, k;
int arr[101];
int dp[10001] = { 1, };

void input() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
}

void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j >= arr[i]) {
        dp[j] = dp[j - arr[i]] + dp[j];
      }
    }
  }
  cout << dp[k] << '\n';
}

int main() {
  input();
  solve();
  return 0;
}
