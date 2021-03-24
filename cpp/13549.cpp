#include <iostream>
#include <queue>
using namespace std;

int n, k;
int arr[100001];
bool visited[100001] = { false };

void solve(int s) {
	deque<pair<int, int>> q;
	visited[s] = true;
	q.push_back({0, s});

	while (!q.empty()) {
		int sec = -q.front().first;
		int x = q.front().second;
		q.pop_front();
		if (x == k) {
			cout << sec << '\n';
			break;
		}
		if (x * 2 <= k + 1 && !visited[x * 2]) {
			q.push_front({-sec, x * 2});
			visited[x * 2] = true;
		}
		if (!visited[x - 1]) {
			q.push_back({-(sec + 1), x - 1});
			visited[x - 1] = true;
		}
		if (!visited[x + 1]) {
			q.push_back({-(sec + 1), x + 1});
			visited[x + 1] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	solve(n);
	return 0;
}
