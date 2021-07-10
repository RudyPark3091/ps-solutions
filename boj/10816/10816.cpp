#include <cstdio>
#define NUM 10000000
using namespace std;

int n, m;
int *arr = new int[2 * NUM + 1];

void input() {
  int t;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    arr[t + NUM]++;
  }
}

void solve(int target) {
  printf("%d ", arr[target + NUM]);
}

int main() {
  int t;
  input();

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &t);
    solve(t);
  }
  return 0;
}
