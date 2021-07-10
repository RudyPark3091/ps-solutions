#include <iostream>
using namespace std;

int main() {
	int arr[5];
	int res = 0;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	for (int i = 0; i < 5; i++) {
		res += arr[i] * arr[i];
	}
	cout << res % 10 << '\n';
	return 0;
}
