#include <iostream>
using namespace std;

int main() {
	int n;
	int arr[5];
	int cnt = 0;

	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (n == arr[i]) cnt += 1;
	}

	cout << cnt << '\n';
	return 0;
}
