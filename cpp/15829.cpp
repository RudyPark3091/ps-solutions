#include <iostream>
#define MOD 1234567891
using namespace std;

int main() {
	int l;
	long long sum = 0;
	long long r = 1;
	string s;
	cin >> l >> s;

	for (int i = 0; i < l; i++) {
		long long c = (int)s[i] - 'a' + 1;
		sum += c * r % MOD;
		r = (r * 31) % MOD;
	}
	cout << sum % MOD << '\n';

	return 0;
}
