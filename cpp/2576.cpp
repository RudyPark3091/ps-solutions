#include <iostream>
using namespace std;

int main() {
	int arr[7];
	int _min = 101;
	int sum = 0;

	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == 0) continue;
		sum += arr[i];
		_min = min(_min, arr[i]);
	}
	
	if (sum == 0 && _min == 101) cout << -1 << '\n';
	else cout << sum << '\n' << _min << '\n';
	return 0;
}
