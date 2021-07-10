## Problem
[acmicpc.net/problem/2110]   
   
## Example
input ->   
5 3   
1   2   8   4   9   
   
output ->   
3   
    
## Logic
이 문제 역시 [1654번 문제], [2805번 문제]와 같이 이분 탐색을 응용해 최적화 문제의 답을 찾는 문제이다.   
이 문제는 주어진 좌표축 위의 점들에 대해 주어진 수만큼의 점을 골랐을 때 점 사이의 간격 중 가장 작은 값이 최대가 되도록 하는 문제라고 할 수 있다.   
일반적인 방법으로 탐색했을 때엔 각 점에 대해 다른 모든 점을 고려애야 하므로 O(N^2)의 시간복잡도를 가진다.   
따라서 이분 탐색을 이용해 시간복잡도를 줄여야 한다.   
start 값은 1, end 값은 좌표평면에서 오른쪽 끝에 있는 집과 왼쪽 끝에 있는 집의 거리로 둔다.   
각 집을 순회하며 이전에 공유기를 설치한 집과의 간격이 mid 보다 크다면 공유기를 설치한다.   
순회가 끝났을때 공유기를 설치한 횟수가 입력받은 C보다 작다면 mid값을 줄여서 탐색하기 위해 right = mid + 1 로 두고 재탐색한다.   
C보다 크다면 mid 값을 늘려서 탐색하기 위해 left = mid + 1 로 두고 재탐색한다.   
이때, 문제의 해답은 과정 중 가장 큰 mid 값이 되므로 적당한 처리를 해준다.   
   
## Source Code
``` cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
long long arr[200000];

void input() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

void solve(long long a, long long b) {
  long long mid = 0;
  long long res = 0;

  while (a <= b) {
    mid = (a + b) / 2;
    int cnt = 1;
    int prev = 0;

    for (int i = 1; i < n; i++) {
      if (arr[i] - arr[prev] >= mid) {
        prev = i;
        cnt++;
      }
    }

    if (cnt < c) {
      b = mid - 1;
    } else {
      a = mid + 1;
      res = max(res, mid);
    }
  }

  cout << res << '\n';
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();
  sort(arr, arr + n);
  solve(1, arr[n-1] - arr[0]);

  return 0;
}
```
   
[acmicpc.net/problem/2110]: https://https://acmicpc.net/problem/2110
[1654번 문제]: https://github.com/RudyPark3091/ps-solutions/tree/master/cpp/1654
[2805번 문제]: https://github.com/RudyPark3091/ps-solutions/tree/master/cpp/2805
