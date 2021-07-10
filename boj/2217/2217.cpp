#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int _min = 10001;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		_min = min(_min, arr[i]);
	}

	sort(arr, arr + n);
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, arr[i] * (n - i));
	}

	cout << res << '\n';
	return 0;
}
