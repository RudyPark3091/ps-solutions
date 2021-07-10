#include <iostream>
using namespace std;

int n;
int a[1001] = { 0, };
int dp[1001] = { 0, };

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        if (dp[j] > cnt) { cnt = dp[j]; }
      }
    }
    dp[i] = cnt + 1;
  }

  int max = 0;
  for (int i = 1; i <=n; i++) {
    if (max < dp[i]) { max = dp[i]; }
  }
  cout << max << '\n';

  return 0;
}