#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[501];
int dp[501][501];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int a, b;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    arr[i] = {a, b};
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; i + j <= n; j++) {
      int k = i + j;
      dp[j][k] = __INT_MAX__;

      for (int w = j; w < k; w++) {
        dp[j][k] = min(dp[j][k], dp[j][w] + dp[w+1][k] + arr[j].first * arr[w].second * arr[k].second);
      }
    }
  }

  cout << dp[1][n] << '\n';
  return 0;
}
