#include <iostream>
using namespace std;

int dp[31][31] = { 0 };

int comb(int n, int r) {
	if (n == r || r == 0) return 1;
	if (dp[n][r] == 0) {
		dp[n][r] = comb(n-1, r-1) + comb(n-1, r);
	}
	return dp[n][r];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	int n, m;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << comb(m, n) << '\n';
	}

	return 0;
}
