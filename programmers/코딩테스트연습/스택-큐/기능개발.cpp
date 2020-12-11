#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;

	for (int i = 0; i < progresses.size(); i++) {
		int rest = 100 - progresses.at(i);
		if (rest % speeds.at(i) != 0) {
			q.push(rest / speeds.at(i) + 1);
		} else {
			q.push(rest / speeds.at(i));
		}
	}

	int p = q.front();
	q.pop();
	int r = 1;
	while (!q.empty()) {
		if (p >= q.front()) {
			r++;
		} else {
			answer.push_back(r);
			p = q.front();
			r = 1;
		}
		q.pop();
	}
	answer.push_back(r);

	return answer;
}

