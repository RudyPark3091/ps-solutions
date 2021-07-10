#include <iostream>
using namespace std;

int main() {
	string n;
	int arr[10] = { 0 };
	cin >> n;

	for (int i = 0; i < n.size(); i++) {
		int num = (int)n[i] - '0';
		arr[num] += 1;
	}

	if ((arr[6] + arr[9]) % 2 == 1)
		arr[6] = (arr[6] + arr[9]) / 2 + 1;
	else
		arr[6] = (arr[6] + arr[9]) / 2;

	arr[9] = arr[6];
	int _max = 0;

	for (int i = 0; i < 10; i++) {
		_max = max(_max, arr[i]);
	}
	cout << _max << '\n';

	return 0;
}
