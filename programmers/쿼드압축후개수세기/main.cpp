#include <vector>
using namespace std;

void solve(vector<vector<int>> &arr, int n, int x, int y) {
  int val = arr[x][y];
  bool flag = false;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[x + i][y + j] != val) flag = true;
    }
  }

  if (n != 1 && !flag) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        arr[x + i][y + j] = -1;
      }
    }
    arr[x][y] = val;
    return;
  }

  int nn = n / 2;
  solve(arr, nn, x, y);
  solve(arr, nn, x + nn, y);
  solve(arr, nn, x, y + nn);
  solve(arr, nn, x + nn, y + nn);
}

int count(vector<vector<int>> arr, int x) {
  int ret = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr.size(); j++) {
      if (arr[i][j] == x) ret += 1;
    }
  }
  return ret;
}

vector<int> solution(vector<vector<int>> arr) {
  int n = arr.size();
  solve(arr, n, 0, 0);

  int zeros = count(arr, 0);
  int ones = count(arr, 1);

  vector<int> answer;
  answer.push_back(zeros);
  answer.push_back(ones);
  return answer;
}

int main() {
  vector<int> tc1 = solution(
    {
      {1, 1, 0, 0},
      {1, 0, 0, 0},
      {1, 0, 0, 1},
      {1, 1, 1, 1},
    }
  );
  assert(tc1[0] == 4);
  assert(tc1[1] == 9);

  vector<int> tc2 = solution({
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 1, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
  });
  assert(tc2[0] == 10);
  assert(tc2[1] == 15);
}
