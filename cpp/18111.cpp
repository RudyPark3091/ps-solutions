#include <iostream>
using namespace std;

int n, m, b;
int arr[501][501];
int max_h = 0;
int min_h = 256;

void input() {
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			max_h = max(max_h, arr[i][j]);
			min_h = min(min_h, arr[i][j]);
		}
	}
}

void solve() {
	int _t = 256 * 500 * 500 * 2;
	int _h = 0;
	for (int h = min_h; h <= max_h; h++) {
		int sum = 0;
		int inv = b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > h) {
					sum += 2 * (arr[i][j] - h);
					inv += arr[i][j] - h;
				} else if (arr[i][j] < h) {
					sum += h - arr[i][j];
					inv -= h - arr[i][j];
				}
			}
		}
		if (inv < 0) continue;
		if (_t >= sum) {
			_t = sum;
			if (_h < h) _h = h;
		}
	}
	cout << _t << ' ' << _h << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
