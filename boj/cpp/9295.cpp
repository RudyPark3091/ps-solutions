#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	int a, b;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << "Case " << i + 1 << ": " << a + b << '\n';
	}

	return 0;
}
