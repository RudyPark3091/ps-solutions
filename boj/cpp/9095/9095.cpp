#include <iostream>
using namespace std;

int t, n;
int arr[11] = {0, 1, 2, 4,};

int init() {
	for (int i = 4; i < 11; i++) {
		arr[i] = arr[i - 3];
	}

	return 0;
}

int solve(int _n) {
	if (_n < 4) {
		return arr[_n];
	} else if (arr[_n] == 0) {
		arr[_n] = solve(_n - 1) + solve(_n - 2) + solve(_n - 3);
	}

	return arr[_n];
}

int main() {
	cin.tie(nullptr);

	cin >> t;

	while (t--) {
		cin >> n;
		cout << solve(n) << '\n';
	}

	return 0;
}
