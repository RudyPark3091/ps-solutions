#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int l;
	int n;
	int p[1001];
	int k[1001];

	int _max1 = 0, _max2 = 0;
	int r1, r2;
	bool visited[1001] = { false };

	cin >> l >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> k[i];
		if (k[i] - p[i] + 1 > _max1) {
			_max1 = k[i] - p[i] + 1;
			r1 = i + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = p[i]; j <= k[i]; j++) {
			if (!visited[j]) {
				visited[j] = true;
				x += 1;
			}
		}
		if (x > _max2) {
			_max2 = x;
			r2 = i + 1;
		}
	}

	cout << r1 << '\n' << r2 << '\n';
	return 0;
}
