/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;
typedef pair<int, int> coord;

int n, m, l, K;
coord arr[101];

void setup() {
	int x, y;
	cin >> n >> m >> l >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		arr[i] = {x, y};
	}
}

bool is_inside(coord x, coord y) {
	return (
			x.first <= y.first && x.second <= y.second &&
			y.first <= x.first + l && y.second <= x.second + l
		);
}

void solve() {
	int ans = 0;

	for (int i = 0; i < K; i++) {
		coord t1 = arr[i];

		for (int j = 0; j < K; j++) {
			coord t2 = arr[j];
			int cnt = 0;

			for (int k = 0; k < K; k++) {
				if (is_inside({t1.first, t2.second}, arr[k])) {
					cnt++;
				}
			}

			ans = max(ans, cnt);
		}
	}

	cout << K - ans << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
