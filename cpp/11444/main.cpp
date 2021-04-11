#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef vector<vector<long long>> matrix;

long long n;

matrix mul(matrix a, matrix b) {
	matrix mat(2, vector<long long>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				mat[i][j] += a[i][k] * b[k][j];
			}
			mat[i][j] %= MOD;
		}
	}
	return mat;
}

void solve() {
	matrix ans = {{1, 0}, {0, 1}};
	matrix m = {{1, 1}, {1, 0}};

	while (n > 0) {
		if (n % 2 != 0) {
			ans = mul(ans, m);
		}
		m = mul(m, m);
		n /= 2;
	}
	cout << ans[1][0] << '\n';
}

int main() {
	cin >> n;
	solve();

	return 0;
}
