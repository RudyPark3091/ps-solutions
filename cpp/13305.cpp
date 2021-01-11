#include <iostream>
using namespace std;

int n;
int road[100001];
int price[100001];

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) cin >> road[i];
	for (int i = 0; i < n; i++) cin >> price[i];
}

long long solve() {
	long long mp = price[0];
	long long res = mp * road[0];
	for (int i = 1; i < n; i++) {
		if (mp > price[i]) {
			mp = price[i];
		}
		res += mp * road[i];
	}
	return res;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	cout << solve() << '\n';
	return 0;
}
