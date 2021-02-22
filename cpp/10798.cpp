#include <iostream>
using namespace std;

int main() {
	string arr[15];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (i >= arr[i].length()) continue;
			if (arr[j][i] != NULL) cout << arr[j][i];
		}
	}
	cout << '\n';
	return 0;
}
