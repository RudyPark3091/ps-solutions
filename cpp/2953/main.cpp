/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int main() {
	int x;
	pair<int, int> m = {1, 0};

	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> x;
			sum += x;
		}
		if (sum > m.second) {
			m.first = i + 1;
			m.second = sum;
		}
	}

	cout << m.first << ' ' << m.second << '\n';
	return 0;
}
