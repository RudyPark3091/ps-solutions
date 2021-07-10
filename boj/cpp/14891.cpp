#include <iostream>
#include <queue>
using namespace std;

deque<int> cog[4];
int k;
pair<int, int> ops[101];

void input() {
	string s;
	int a, b;
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			cog[i].push_back((int)s[j] - '0');
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		ops[i] = {a, b};
	}
}

void rotate_clock(int x) {
	int item = cog[x].back();
	cog[x].push_front(item);
	cog[x].pop_back();
}

void rotate_counterclock(int x) {
	int item = cog[x].front();
	cog[x].push_back(item);
	cog[x].pop_front();
}

void solve() {
	for (int t = 0; t < k; t++) {
		pair<int, int> op = ops[t];
		int target = op.first - 1;
		bool is_clockwise = op.second == 1 ? true : false;
		
		int r = target;
		int l = target;
		for (int i = target; i < 3; i++) {
			if (cog[i][2] == cog[i + 1][6]) {
				r = i;
				break;
			} else if (i == 2) r = 3;
		}
		for (int i = target; i > 0; i--) {
			if (cog[i][6] == cog[i - 1][2]) {
				l = i;
				break;
			} else if (i == 1) l = 0;
		}
		for (int i = target; i <= r; i++) {
			if (is_clockwise) {
				rotate_clock(i);
				is_clockwise = false;
			} else {
				rotate_counterclock(i);
				is_clockwise = true;
			}
		}
		is_clockwise = op.second == 1 ? false : true;
		for (int i = target - 1; i >= l; i--) {
			if (is_clockwise) {
				rotate_clock(i);
				is_clockwise = false;
			} else {
				rotate_counterclock(i);
				is_clockwise = true;
			}
		}
	}
	
	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (cog[i].front()) res += 1 << i;
	}
	cout << res << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}
