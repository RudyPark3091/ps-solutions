#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	sort(jobs.begin(), jobs.end(),
			[](vector<int> a, vector<int> b) { return a[0] < b[0]; });
	priority_queue<vector<int>, vector<vector<int>>, cmp> q;
	int n = jobs.size();
	int i = 0;
	int sum = 0;
	int t = 0;

	while (i < n || !q.empty()) {
		if (i < n && jobs[i][0] <= t) {
			q.push(jobs[i]);
			i += 1;
		} else {
			if (!q.empty()) {
				auto item = q.top();
				t += item[1];
				sum += t - item[0];
				q.pop();
			} else t = jobs[i][0];
		}
	}

	return sum / n;
}

int main() {
	cout << solution(
			{{0, 3}, {1, 9}, {2, 6}}
			) << endl;
	return 0;
}
