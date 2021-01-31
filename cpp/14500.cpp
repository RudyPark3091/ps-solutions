#include <iostream>
using namespace std;

int n, m;
int arr[501][501];
int shapes[5][3][2] = {
	{ {0, 1}, {0, 2}, {0, 3} },
	{ {0, 1}, {1, 0}, {1, 1} },
	{ {1, 0}, {2, 0}, {2, 1} },
	{ {1, 0}, {1, 1}, {2, 1} },
	{ {0, 1}, {1, 1}, {0, 2} },
};

void input () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

bool bdry(int nx, int ny) {
	return 0 <= nx && nx < n && 0 <= ny && ny < m;
}

int rotate90(int x, int y) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int _sum = arr[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x - shapes[i][j][1];
			int ny = y + shapes[i][j][0];
			if (bdry(nx, ny)) _sum += arr[nx][ny];
		}
		sum = max(_sum, sum);
		_sum = arr[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x - shapes[i][j][1];
			int ny = y - shapes[i][j][0];
			if (bdry(nx, ny)) _sum += arr[nx][ny];
		}
		sum = max(_sum, sum);
	}
	return sum;
}

int rotate180(int x, int y) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int _sum = arr[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x - shapes[i][j][0];
			int ny = y - shapes[i][j][1];
			if (bdry(nx, ny)) _sum += arr[nx][ny];
		}
		sum = max(_sum, sum);
		_sum = arr[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x - shapes[i][j][0];
			int ny = y + shapes[i][j][1];
			if (bdry(nx, ny)) _sum += arr[nx][ny];
		}
		sum = max(_sum, sum);
	}
	return sum;
}

int rotate270(int x, int y) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int _sum = arr[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x + shapes[i][j][1];
			int ny = y + shapes[i][j][0];
			if (bdry(nx, ny)) _sum += arr[nx][ny];
		}
		sum = max(_sum, sum);
		_sum = arr[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x + shapes[i][j][1];
			int ny = y - shapes[i][j][0];
			if (bdry(nx, ny)) _sum += arr[nx][ny];
		}
		sum = max(_sum, sum);
	}
	return sum;
}

int check(int x, int y) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int _sum = arr[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x + shapes[i][j][0];
			int ny = y + shapes[i][j][1];
			if (bdry(nx, ny)) _sum += arr[nx][ny];
		}
		sum = max(_sum, sum);
		_sum = arr[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x + shapes[i][j][0];
			int ny = y - shapes[i][j][1];
			if (bdry(nx, ny)) _sum += arr[nx][ny];
		}
		sum = max(_sum, sum);
	}
	return sum;
}

void solve() {
	int _max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			_max = max(_max, check(i, j));
			_max = max(_max, rotate90(i, j));
			_max = max(_max, rotate180(i, j));
			_max = max(_max, rotate270(i, j));
			/* _max = max(_max, reverse(i, j)); */
		}
	}
	cout << _max << '\n';
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	input();
	solve();

	return 0;
}
