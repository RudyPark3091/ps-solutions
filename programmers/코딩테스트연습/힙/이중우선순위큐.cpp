#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
		priority_queue<int, vector<int>, less<int>> max_q;
		priority_queue<int, vector<int>, greater<int>> min_q;
		int cnt = 0;

		for (int i = 0; i < operations.size(); i++) {
			bool ins = operations[i][0] == 'I';
			int num = stoi(operations[i].substr(2));
			bool d_min = operations[i][2] == '-';
			bool d_max = operations[i][2] != '-';

			if (cnt == 0) {
				while (!max_q.empty()) max_q.pop();
				while (!min_q.empty()) min_q.pop();
			}

			if (ins) {
				max_q.push(num);
				min_q.push(num);
				cnt++;
			} else if (d_max && !max_q.empty()) {
				max_q.pop();
				cnt--;
			} else if (d_min && !min_q.empty()) {
				min_q.pop();
				cnt--;
			}
		}

		vector<int> ans(2);
		ans[0] = cnt != 0 ? max_q.top() : 0;
		ans[1] = cnt != 0 ? min_q.top() : 0;
    return ans;
}

int main() {
	auto res = solution(
			{"I 16","D 1"}
			);
	for (auto item: res) cout << item << " ";

	auto res2 = solution(
			{"I 7","I 5","I -5","D -1"}
			);
	for (auto item: res2) cout << item << " ";

	return 0;
}
