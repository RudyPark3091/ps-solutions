#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int n, k;
pair<int, int> arr[MAX];
bool visited[MAX] = { false };

void solve(int s) {
	queue<pair<int, int>> q;
	visited[s] = true;
	q.push({0, s});

	while (!q.empty()) {
		int sec = q.front().first;
		int x = q.front().second;
		q.pop();

		if (x * 2 < MAX && !visited[x * 2]) {
			q.push({sec + 1, x * 2});
			visited[x * 2] = true;
			arr[x * 2] = {sec + 1, x};
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			q.push({sec + 1, x - 1});
			visited[x - 1] = true;
			arr[x - 1] = {sec + 1, x};
		}
		if (x + 1 < MAX && !visited[x + 1]) {
			q.push({sec + 1, x + 1});
			visited[x + 1] = true;
			arr[x + 1] = {sec + 1, x};
		}
	}

	cout << arr[k].first << '\n';
	int i = k;
	vector<int> v;
	while (true) {
		if (arr[i].first == 0) break;
		v.push_back(i);
		i = arr[i].second;
	}
	cout << n << ' ';
	for (int j = v.size() - 1; j >= 0; j--) {
		cout << v[j] << ' ';
	}
	cout << '\n';
}

int main() {
	cin >> n >> k;
	solve(n);
	return 0;
}
