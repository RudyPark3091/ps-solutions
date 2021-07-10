#include <iostream>
#include <algorithm>
using namespace std;

int n, m, sum = 0;
int arr[101];
int v[101];
int dp[10001];

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
		sum += v[i];
  }
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= 1; j--) {
			if (j - v[i] >= 0) {
				dp[j] = max(dp[j], dp[j-v[i]] + arr[i]);
			}
		}
	}

	int i;
	for (i = 1; i < sum && dp[i] < m; i++);
	cout << i << '\n';
}

int main() {
	input();
	solve();

  return 0;
}
