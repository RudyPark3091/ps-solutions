## Problem
[acmicpc.net/problem/12015]
   
## Example
input ->   
6   
10 20 10 30 20 50   
   
output ->   
4   
   
## Logic
이 문제는 [11053번 문제]의 응용버전이라고 할 수 있다.   
11053번 문제는 수열의 크기가 1,000이라 O(n^2)의 알고리즘으로도 해결할 수 있었다.   
이번에는 수열의 크기가 1,000,000이라 이분 탐색을 이용한 최적화를 사용해야 한다.   
수열의 각 원소에 대해 순회하는 것으로 시작한다.   
해당 원소를 현재 부분수열의 오른쪽 끝에 있는 원소와 비교한다.   
만약 해당 원소가 크다면 부분수열의 오른쪽에 push해준다.   
해당 원소가 작다면 부분수열에서 해당 원소보다 작은 원소들 중 가장 오른쪽에 있는 값 다음 값을 해당 원소로 갱신한다.   
이 작업은 algorithm STL의 lower_bound 함수로 쉽게 진행할 수 있다.   
이 방법으로 수열을 순회한 결과가 최장 부분수열이 된다.   
왜 이 문제가 이분탐색 알고리즘으로 분류되는지 궁금했는데, lower_bound함수가 내부적으로 이분탐색을 이용해 구현되었다고 한다.   
lower_bound함수는 반환형이 iterator형이므로 요소에 접근할 때엔 * 을 붙여아 함을 유의한다.   
   
## Source Code
``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, num;
vector<int> lcs;

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> num;
    if (lcs.empty() || num > lcs.back()) {
      lcs.push_back(num);
    } else {
      *lower_bound(lcs.begin(), lcs.end(), num) = num;
    }
  }

  cout << lcs.size() << '\n';
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  solve();

  return 0;
}
```
   


[acmicpc.net/problem/12015]: https://acmicpc.net/problem/12015
[11053번 문제]: https://github.com/RudyPark3091/ps-solutions/tree/master/cpp/11053
