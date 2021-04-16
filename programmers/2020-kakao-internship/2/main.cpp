/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
function<ll (ll, ll)> ops[3] = {
	[](ll a, ll b) -> ll { return a + b; },
	[](ll a, ll b) -> ll { return a - b; },
	[](ll a, ll b) -> ll { return a * b; },
};
vector<string> tokens;
int order[6][3] = {
	{0, 1, 2},
	{0, 2, 1},
	{1, 0, 2},
	{1, 2, 0},
	{2, 0, 1},
	{2, 1, 0},
};

string op_to_char(int op) {
	switch (op) {
		case 0:
			return "+";
		case 1:
			return "-";
		case 2:
			return "*";
	}
	return "";
}

void calc(int op, vector<string>& _tokens) {
	vector<string>::iterator iter = _tokens.begin();
	for (int i = 0; i < _tokens.size(); i++) {
		cout << _tokens[i] << " ";
	}
	cout << '\n';

	while (iter < _tokens.end()) {
		if (*iter == op_to_char(op)) {
			ll a = stoll((*(iter - 1)).c_str());
			ll b = stoll((*(iter + 1)).c_str());

			_tokens.erase(iter - 1);
			_tokens.erase(iter - 1);
			*(iter - 1) = to_string(ops[op](a, b));
		} else {
			iter++;
		}
	}
}

void parse(string expression) {
	string buf = "";
	int idx = 0;

	for (int i = 0; i < n; i++) {
		switch (expression[i]) {
			case '+':
			case '-':
			case '*':
				tokens.push_back(buf);
				tokens.push_back(expression.substr(i, 1));
				buf = "";
				break;

			default:
				buf += expression[i];
		}
	}
	tokens.push_back(buf);
}

ll solution(string expression) {
	ll ans = 0;
	n = expression.length();
	parse(expression);

	for (int i = 0; i < 6; i++) {
		vector<string> _tokens = tokens;
		for (int j = 0; j < 3; j++) {
			calc(order[i][j], _tokens);
		}

		ll result = atol(_tokens[0].c_str());
		ans = max(ans, abs(result));
	}

	return ans;
}

int main() {
	cout << solution("100-200*300-500+20") << '\n';

	return 0;
}
