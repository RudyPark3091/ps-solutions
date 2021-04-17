/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
typedef pair<int, int> ii;

vector<int> solution(vector<string> gems) {
	vector<int> ans;
	unordered_map<string, int> m;

	int n = gems.size();
	set<string> s;
	
	for (auto gem: gems) s.insert(gem);
	for (auto item: s) m[item] = 0;
	int N = s.size();

	int left = 0, right = 0;
	int low = 1, high = 100001;
	int cnt = 1;
	m[gems[0]] = 1;

	while (left <= right) {
		if (cnt < N && right < n - 1) {
			right += 1;

			cnt += m[gems[right]] == 0 ? 1 : 0;
			m[gems[right]] += 1;
		} else if (cnt == N) {
			int d1 = right - left;
			int d2 = high - low;
			if (d1 < d2) {
				low = left;
				high = right;
			}

			if (m[gems[left]] == 1) cnt--;
			m[gems[left]] -= 1;
			left += 1;
		} else {
			break;
		}
	}

	ans.push_back(low + 1);
	ans.push_back(high + 1);
	return ans;
}

int main() {
	vector<string> v = {
		"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"
	};
	auto ans = solution(v);
	cout << ans[0] << " " << ans[1] << '\n';

	return 0;
}

