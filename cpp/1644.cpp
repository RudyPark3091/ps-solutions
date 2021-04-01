#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<bool> p = { false };

void get_primes() {
	p.reserve(n + 1);
	for (int i = 2; i * i <= n + 1; i++) {
		if (p[i]) continue;
		for (int j = i * i; j <= n; j += i) p[j] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (!p[i]) arr.push_back(i);
	}
}

void solve() {
	get_primes();

	int l = 0;
	int r = 0;
	int sum = arr.size() == 0 ? 0 : arr[0];
	int ans = 0;

	while (l < r + 1 && r < arr.size()) {
		if (sum == n) {
			sum -= arr[l];
			l++;
			ans++;
		} else if (sum < n) {
			r++;
			sum += arr[r];
		} else if (sum > n) {
			sum -= arr[l];
			l++;
		}
	}

	cout << ans << '\n';
}

int main() {
	cin >> n;
	solve();
	return 0;
}
