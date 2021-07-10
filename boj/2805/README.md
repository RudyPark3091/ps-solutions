## Problem
[acmicpc.net/problem/2805]
   
## Example
input ->   
4 7   
20 15 10 17   
   
ouput ->   
15   
   
## Logic
이 문제는 [1654번 문제]와 비슷한 구조를 가진다.   
이진 탐색을 이용해 최대/최솟값을 찾아내는 알고리즘이다.   
나무 높이의 최댓값을 end값, 1을 start값으로 잡고 이진 탐색을 실시한다.   
잘랐을때 나오는 나무의 길이가 m보다 작다면 자르는 나무의 높이를 줄이고, 크다면 나무의 높이를 늘린다.   
이 과정을 반복하여 나오는 높이의 최댓값을 구한다.   
잘린 나무의 길이합을 구하는 과정에서 나무의 높이가 자르는 높이보다 높을때만 더해진다는것에 유의한다.   
   
## Source Code
``` cpp
#include <iostream>
using namespace std;

int n, m;
int res;
long long max_height = 0;
int arr[1000000];

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (max_height < arr[i])
      max_height = arr[i];
  }
}

void solve(long long a, long long b) {
  long long mid = 0;

  while (a <= b) {
    mid = (a + b) / 2;
    long long len = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i] > mid)
        len += arr[i] - mid;
    }

    if (len < m) {
      b = mid - 1;
    } else {
      if (res < mid)
        res = mid;
      a = mid + 1;
    }
  }

  cout << res << '\n';
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();
  solve(1, max_height);

  return 0;
}
```

[acmicpc.net/problem/2805]: https://www.acmicpc.net/problem/2805
[1654번 문제]: https://github.com/RudyPark3091/ps-solutions/tree/master/cpp/1654
