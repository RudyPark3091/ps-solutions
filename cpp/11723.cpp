#include <iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int m;
	string op;
	int x;
	int s = 1 << 21;

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> op;
		char o = op[0];
		if (op == "all") {
			s = ~(1 << 21);
			continue;
		}
		else if (o == 'e') {
			s = 1 << 21;
			continue;
		}

		cin >> x;
		if (o == 'a') {
			s = s | ( 1 << x );
		} else if (o == 'r') {
			s = s & ~(1 << x);
		} else if (o == 'c') {
			if (s & 1 << x) cout << 1 << '\n';
			else cout << 0 << '\n';
		} else if (o == 't') {
			s = s ^ 1 << x;
		} else if (o == 'e') {
			s = 1 << 21;
		}
	}
	return 0;
}
