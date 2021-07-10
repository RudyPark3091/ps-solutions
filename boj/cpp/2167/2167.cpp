#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m;
	int arr[301][301] = { 0 };
	int k;
	int a, b, x, y;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> k;
	for (int _i = 0; _i < k; _i++) {
		cin >> a >> b >> x >> y;
		int sum = 0;
		for (int i = a - 1; i <= x - 1; i++) {
			for (int j = b - 1; j <= y - 1; j++) {
				sum += arr[i][j];
			}
		}
		cout << sum << '\n';
	}

	return 0;
}
