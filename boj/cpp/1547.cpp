#include <iostream>
using namespace std;

int main() {
	int m, x, y;
	int arr[] = {0, 1, 0, 0};
	int now = 1;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (arr[x] == 1) {
			arr[x] = 0;
			arr[y] = 1;
		} else if (arr[y] == 1) {
			arr[y] = 0;
			arr[x] = 1;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (arr[i] == 1) cout << i << '\n';
	}
	return 0;
}
