#include <iostream>
using namespace std;

int n;
int t[16], p[16];
int dp[16];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];
}

int solve() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (i + t[i] <= n) {
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}
	return dp[n];
}

int main() {
	input();
	cout << solve() << '\n';
	return 0;
}
