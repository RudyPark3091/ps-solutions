#include <iostream>
#define MOD 1000000007
using namespace std;

int n, m;
int d[1002][1002] = { 0 };

int solve(int x, int y) {
	d[0][0] = 1;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % MOD;
			d[i][j] = (d[i][j] + d[i][j - 1]) % MOD;
		}
	}
	return d[x][y];
}

int main() {
	cin >> n >> m;
	cout << solve(n, m) << '\n';
	return 0;
}

