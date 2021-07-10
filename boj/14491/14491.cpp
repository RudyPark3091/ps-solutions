#include <iostream>
using namespace std;

int main() {
	int t;
	int r = 1;
	int res = 0;
	cin >> t;
	
	while (t >= 1) {
		int _r = t % 9;
		t /= 9;
		res += r * _r;
		r *= 10;
	}
	cout << res << '\n';
	return 0;
}
