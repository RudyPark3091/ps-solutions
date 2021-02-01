#include <iostream>
using namespace std;

int main() {
	int n, x;
	int sum = 0, _max = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		_max = max(_max, x);
	}

	cout << sum - _max << '\n';
	return 0;
}
