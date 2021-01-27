#include <iostream>
#include <vector>
using namespace std;

bool check(string x, string y) {
	int cnt = 0;
	int n = x.size();
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == y[i]) cnt++;
	}
	if (cnt == n - 1) return true;
	return false;
}

int dfs(vector<string> words, vector<bool>& visited, int n, string target, string word, int depth) {
	int res = 0;
	if (word == target) return depth;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && check(word, words[i])) {
			visited[i] = true;
			res = dfs(words, visited, n, target, words[i], depth + 1);
			visited[i] = false;
		}
	}
	return res;
}

int solution(string begin, string target, vector<string> words) {
	int n = words.size();
	bool flag = true;

	for (int i = 0; i < n; i++) {
		if (words[i] == target) flag = false;
	}
	if (flag) return 0;

	vector<bool> visited(51);

	int answer = dfs(words, visited, n, target, begin, 0);
	return answer;
}

int main() {
	cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << '\n';
	cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << '\n';
	return 0;
}
