#include <iostream>
#include <climits>
using namespace std;

int n, maxval = INT_MIN;
int arr[100001];
int dp[100001];

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (maxval < arr[i]) { maxval = arr[i]; }
  }
}

void solve() {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (sum + arr[i] < arr[i]) {
      sum = arr[i];
    } else {
      sum += arr[i];
    }
    dp[i] = sum;
  }

  int max = 0;
  for (int i = 1; i <= n; i++) {
    if (max < dp[i]) {
      max = dp[i];
    }
  }
  if (max <= 0) {
    cout << maxval << '\n';
  } else {
    cout << max << '\n';
  }
}

int main() {
  input();
  solve();

  return 0;
}
