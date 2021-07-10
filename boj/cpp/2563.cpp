#include <iostream>
using namespace std;

int main() {
	int n;
	int x, y;
	int sum = 0;
	bool graph[101][101] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				graph[x + j][y + k] = true;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (graph[i][j]) {
				sum += 1;
			}
		}
	}

	cout << sum << '\n';
	return 0;
}
