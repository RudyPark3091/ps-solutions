/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
using namespace std;

int calc(int x) {
	int sum = 0;
	int i = 1;
	int cnt = 0;
	int end = 0;

	while (end < x) {
		sum += i;
		cnt++;
		end++;
		if (cnt == i) {
			i++;
			cnt = 0;
		}
	}
	return sum;
}

void solve(int a, int b) {
	cout << calc(b) - calc(a - 1) << '\n';
}

int main() {
	int a, b;
	cin >> a >> b;
	solve(a, b);

	return 0;
}
