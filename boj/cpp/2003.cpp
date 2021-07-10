#include <iostream>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;

	long long arr[10001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long x = 0;
	long long y = 0;
	long long sum = 0;
	int ans = 0;

	while (true) {
		if (sum < m) {
			if (y == n) break;
			sum += arr[y];
			y++;
		} else if (sum >= m) {
			if (sum != m && x == y) break;
			sum -= arr[x];
			x++;
		}

		if (sum == m) {
			ans++;
		}
	}

	cout << ans << '\n';
	return 0;
}
