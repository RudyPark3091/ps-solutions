#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int n, k;
bool graph[MAX];
queue<int> q;

int bfs(int s, int d) {
	int ret = 0;
	q.push(s);

	while (true) {
		queue<int> q2;

		while (!q.empty()) {
			int f = q.front();
			q.pop();

			if (f == d)
				return ret;

			if (f+1 < MAX && !graph[f+1]) {
				q2.push(f+1);
				graph[f+1] = true;
			}

			if (f-1 >= 0 && !graph[f-1]) {
				q2.push(f-1);
				graph[f-1] = true;
			}

			if (f*2 < MAX && !graph[f*2]) {
				q2.push(f*2);
				graph[f*2] = true;
			}
		}

		q = q2;
		ret++;
	}
}

int main() {
	cin >> n >> k;
	cout << bfs(n, k) << '\n';
	return 0;
}
