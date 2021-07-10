/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, r;
int ans = 0;
int arr[51];
vector<int> roots;
vector<int> graph[51];

void setup() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == -1) roots.push_back(i);
		else graph[arr[i]].push_back(i);
	}
	cin >> r;
}

void dfs(int x) {
	if (graph[x].size() == 0) ans++;
	for (int i = 0; i < graph[x].size(); i++) {
		dfs(graph[x][i]);
	}
}

void solve() {
	graph[r].clear();
	int parent = arr[r];
	if (parent != -1) {
		auto pos = find(graph[parent].begin(), graph[parent].end(), r);
		graph[parent].erase(pos);
	} else {
		ans--;
	}

	for (int i = 0; i < roots.size(); i++) {
		dfs(roots[i]);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
