#include <iostream>
using namespace std;

int n, r, c;
int num = 0;

int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x; 
	}
	return res;
}

int solve(int size, int x, int y, int _n) {
	if (size == 1) return _n;
	int nx = x - size / 2;
	int ny = y - size / 2;
	if (x < size / 2) {
		if (y < size / 2) return solve(size / 2, x, y, _n);
		else return solve(size / 2, x, ny, _n + (size / 2) * (size / 2));
	} else {
		if (y < size / 2) return solve(size / 2, nx, y, _n + (size / 2) * (size));
		else return solve(size / 2, nx, ny, _n + (size / 2) * (size / 2) * 3);
	}
}

int main() {
	cin >> n >> r >> c;

	int size = pow(2, n);
	cout << solve(size, r, c, 0) << '\n';
	return 0;
}
