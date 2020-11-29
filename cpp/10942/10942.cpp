#include <iostream>
using namespace std;

int n, m;
int arr[2001];
bool dp[2001][2001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int s, e;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	cin >> m;

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		if (arr[i] == arr[i-1]) {
			dp[i-1][i] = 1;
		}
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l; i++) {
			int j = i + l;
			if (arr[i] == arr[j] && dp[i+1][j-1] == 1) {
				dp[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}
