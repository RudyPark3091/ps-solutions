#include <iostream>
using namespace std;

int main() {
	int k;
	int a = 1;
	int b = 0;

	cin >> k;
	for (int i = 0; i < k; i++) {
		int t = b;
		b = b + a;
		a = t;
	}

	cout << a << ' ' << b << '\n';
	return 0;
}
