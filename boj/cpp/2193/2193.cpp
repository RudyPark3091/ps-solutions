#include <iostream>
using namespace std;
typedef long long ll;

pair<ll, ll> arr[91] = {
	make_pair(0, 0),
	make_pair(0, 1),
	make_pair(1, 0),
	make_pair(1, 1),
};

pair<ll, ll> solve(ll _n) {
	if (_n < 4) return arr[_n];
	if (arr[_n] == (pair<ll, ll>) make_pair(0, 0)) {
		arr[_n] = make_pair(solve(_n - 1).first + solve(_n - 1).second, solve(_n - 1).first);
	}
	return arr[_n];
}

int main() {
	int n;
	cin >> n;

	auto r = solve(n);
	cout << r.first + r.second << '\n';
	return 0;
}
