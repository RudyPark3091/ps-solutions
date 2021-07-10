#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	int a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b;
		int g = __gcd(a, b);
		cout << g * (a/g) * (b/g) << '\n';
	}

	return 0;
}
