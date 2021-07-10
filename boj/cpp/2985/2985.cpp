#include <iostream>
#include <functional>
using namespace std;

function<int (int, int)> fn[4] = {
	[](int a, int b) -> int { return a + b; },
	[](int a, int b) -> int { return a - b; },
	[](int a, int b) -> int { return a * b; },
	[](int a, int b) -> int { return a / b; },
};

char op[4] = {'+', '-', '*', '/'};

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 0; i < 4; i++) {
		if (fn[i](a, b) == c) {
			printf("%d%c%d=%d\n", a, op[i], b, c);
			break;
		} else if (fn[i](b, c) == a) {
			printf("%d=%d%c%d\n", a, b, op[i], c);
			break;
		}
	}
	return 0;
}
