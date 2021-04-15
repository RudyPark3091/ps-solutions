#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> coord;

int n;
bool is_right_hand;
coord lp = {3, 0};
coord rp = {3, 2};

coord to_coord(int num) {
	if (num == 0) return {3, 0};
	return {(num - 1) / 3, (num - 1) % 3};
}

int dist(coord a, coord b) {
	int x1 = a.first;
	int x2 = b.first;
	int y1 = a.second;
	int y2 = b.second;
	return abs(x1 - x2) + abs(y1 - y2);
}

string solution(vector<int> numbers, string hand) {
	n = numbers.size();
	is_right_hand = hand == "right";
	string ans = "";

	for (int i = 0; i < n; i++) {
		bool l = numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7;
		bool r = numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9;
		if (l) {
			ans += "L";
			lp = to_coord(numbers[i]);
		} else if (r) {
			ans += "R";
			rp = to_coord(numbers[i]);
		} else {
			int ld = dist(lp, to_coord(numbers[i]));
			int rd = dist(rp, to_coord(numbers[i]));
			if (ld < rd) {
				ans += "L";
				lp = to_coord(numbers[i]);
			} else if (rd < ld) {
				ans += "R";
				rp = to_coord(numbers[i]);
			} else {
				if (is_right_hand) {
					ans += "R";
					rp = to_coord(numbers[i]);
				} else {
					ans += "L";
					lp = to_coord(numbers[i]);
				}
			}
		}
	}
	return ans;
}

int main() {
	cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

	cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right") << '\n';

	return 0;
}
