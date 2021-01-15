#include <iostream>
#include <iomanip>
#include <cstring>
#define SIZE 26
using namespace std;

int n = 0;
bool flag = true;
double sum = 0;
char strs[100001][81];

struct trie {
	bool is_terminal;
	trie* children[SIZE];
	int cnt;

	trie() : is_terminal(false), cnt(0) {
		for (int i = 0; i < SIZE; i++) children[i] = nullptr;
	}

	~trie() {
		for (int i = 0; i < SIZE; i++) {
			if (children[i] != nullptr) delete children[i];
		}
	}

	void insert(char* key) {
		if (*key == '\0') is_terminal = true;
		else {
			int idx = *key-'a';
			if (children[idx] == nullptr) {
				this -> cnt += 1;
				children[idx] = new trie();
			}
			children[idx] -> insert(key + 1);
		}
	}

	void search_depth(char* key) {
		if (*key == '\0') return;

		if (flag) {
			flag = false;
			sum += 1;
		} else {
			if (is_terminal) sum += 1;
			else if (cnt > 1) sum += 1;
		}

		children[*key - 'a'] -> search_depth(key + 1);
	}
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	while (cin >> n) {
		trie* t = new trie();
		sum = 0; 

		for (int i = 0; i < n; i++) {
			cin >> strs[i];
			t -> insert(strs[i]);
		}

		for (int i = 0; i < n; i++) {
			flag = true;
			t -> search_depth(strs[i]);
		}

		cout << fixed << setprecision(2) << sum / (double)n << '\n';
		delete t;
	}

	return 0;
}
