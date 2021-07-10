#include <iostream>
using namespace std;
typedef pair<char, char> Node;

int n;
char root, l, r;
Node tree[26];

int ctoi(char c) {
	if (c != '.') return (int)c - 'A';
	else return -1;
}

char itoc(int i) {
	if (i != -1) return (char)(i + 'A');
	else return '.';
}

void preorder(int idx) {
	cout << itoc(idx);
	int left = tree[idx].first;
	int right = tree[idx].second;
	if (left != -1) preorder(left);
	if (right != -1) preorder(right);
	if (left == -1 && right == -1) return;
}

void inorder(int idx) {
	int left = tree[idx].first;
	int right = tree[idx].second;
	if (left != -1) inorder(left);
	cout << itoc(idx);
	if (right != -1) inorder(right);
	if (left == -1 && right == -1) return;
}

void postorder(int idx) {
	int left = tree[idx].first;
	int right = tree[idx].second;
	if (left != -1) postorder(left);
	if (right != -1) postorder(right);
	cout << itoc(idx);
	if (left == -1 && right == -1) return;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> root >> l >> r;
		tree[ctoi(root)] = {ctoi(l), ctoi(r)};
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';

	return 0;
}
