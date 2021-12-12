#include <vector>
#include <queue>
#include <tuple>
using namespace std;

bool visited[101][101];
int moves[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int solution(vector<vector<int>> maps) {
  int n = maps.size();
  int m = maps[0].size();

  queue<tuple<int, int, int>> q;
  visited[0][0] = true;
  q.push({0, 0, 1});

  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    int x = get<0>(now);
    int y = get<1>(now);
    int w = get<2>(now);

    if (x == n - 1 && y == m - 1) return w;

    for (int i = 0; i < 4; i++) {
      int nx = x + moves[i][0];
      int ny = y + moves[i][1];
      bool bdry = 0 <= nx && nx < n && 0 <= ny && ny < m;

      if (bdry && !visited[nx][ny] && maps[nx][ny]) {
        q.push({nx, ny, w + 1});
        visited[nx][ny] = true;
      }
    }
  }

  return -1;
}

int main() {
  int tc1 = solution({
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 0, 0, 1},
  });
  assert(tc1 == 11);

  int tc2 = solution({
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 1, 1, 0, 0},
    {0, 0, 0, 0, 1},
  });
  assert(tc2 == -1);
  return 0;
}
