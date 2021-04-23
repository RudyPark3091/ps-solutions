/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n1, n2, t;
vector<pair<char, bool>> ant;

void setup() {
	char c;
	cin >> n1 >> n2;
	for (int i = 0; i < n1; i++) {
		cin >> c;
		ant.push_back({c, true});
	}
	reverse(ant.begin(), ant.end());

	for (int i = 0; i < n2; i++) {
		cin >> c;
		ant.push_back({c, false});
	}
	cin >> t;
}

void swap(int x, int y) {
	pair<char, bool> tmp = ant[x];
	ant[x] = ant[y];
	ant[y] = tmp;
}

void solve() {
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < ant.size() - 1; j++) {
			if (ant[j].second && ant[j].second != ant[j + 1].second) {
				swap(j, j + 1);
				j++;
			}
		}
	}

	for (int i = 0; i < ant.size(); i++) {
		cout << ant[i].first;
	}
	cout << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
