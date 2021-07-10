#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n;
	int _min = 10000;
	int sum = 0;
	vector<int> arr;

	for (int i = 1; i * i <= 10000; i++) {
		arr.push_back(i * i);
	}
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		int x = *lower_bound(arr.begin(), arr.end(), i);
		_min = _min == 10000 ? x : _min;
		if (i == x) sum += x;
	}
	if (sum == 0) cout << -1 << '\n';
	else cout << sum << '\n' << _min << '\n';

	return 0;
}
