/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 30 * 500 + 1;

int n, m, sum = 0;
int weight[31];
int check[8];
bool dp[31][MAX] = { false };
bool visited[31][MAX] = { false };

void setup() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
		sum += weight[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> check[i];
	}
}

void iter(int depth, int _w) {
	if (depth > n) return;
	if (visited[depth][_w]) return;

	dp[depth][_w] = true;
	visited[depth][_w] = true;

	iter(depth + 1, _w + weight[depth]);
	iter(depth + 1, _w);
	iter(depth + 1, abs(_w - weight[depth]));
}

void solve(int a, int b) {
	iter(a, b);
	for (int i = 0; i < m; i++) {
		int w = check[i];
		if (w < MAX && dp[n][w]) cout << "Y" << ' ';
		else cout << "N" << ' ';
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve(0, 0);

	return 0;
}
