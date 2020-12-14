#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m;
	map<string, map<int, int>> mm;

	// saving infos
	for (int i = 0; i < genres.size(); i++) {
		m[genres[i]] += plays[i];
		mm[genres[i]][i] = plays[i];
	}

	while (!m.empty()) {
		int mmax = 0;
		string genre = "";
		for (auto item: m) {
			if (mmax < item.second) {
				genre = item.first;
				mmax = item.second;
			}
		}

		for (int i = 0; i < 2; i++) {
			int mmmax = 0;
			int idx = -1;
			for (auto item: mm[genre]) {
				if (mmmax < item.second) {
					mmmax = item.second;
					idx = item.first;
				}
			}

			if (idx == -1) break;
			answer.push_back(idx);
			mm[genre].erase(idx);
		}
		m.erase(genre);
	}
	return answer;
}

