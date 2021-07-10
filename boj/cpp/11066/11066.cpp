#include <iostream>
#include <algorithm>
using namespace std;

int t, k;
int arr[501] = { 0 };
int dp[501][501] = { 0 };
int sum[501];

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> k;
    for (int j = 1; j <= k; j++) {
      cin >> arr[j];
      sum[j] = sum[j-1] + arr[j];
    }

    for (int x = 1; x < k; x++) {
      for (int y = 1; x + y <= k; y++) {
        int z = x + y;
        dp[y][z] = __INT_MAX__;

        for (int w = y; w < z; w++) {
          dp[y][z] = min(dp[y][z], dp[y][w] + dp[w+1][z] + sum[z] - sum[y - 1]);
        }
      }
    }

    cout << dp[1][k] << '\n';
  }
  return 0;
}
