## Problem
[acmicpc.net/problem/7579]  
  
## Example
input ->  
5 60  
30 10 20 35 40  
3 0 3 5 4  
  
output ->  
6  
  
## Logic
[12865번 문제]와 같은 배낭 문제의 응용이다.  
배낭 문제는 주어진 무게 한도 내에서 최대한의 가치를 선택하는 문제이다.  
이 문제는 주어진 무게보다 큰 한도 내에서 최소한의 가치를 선택하는 문제라고 할 수 있다.  
이번 문제에선 dp를 1차원 배열로 두고 문제를 푼다.  
배낭 문제의 dp배열값이 배낭안 물건 가치의 총합이라고 한다면 이 문제에서 dp배열값은 현재 확보한 메모리의 최대값으로 둔다.  
즉, dp[i]의 값은 앱을 비활성화 하는데 든 비용의 합이 i일때 확보할 수 있는 최대 메모리를 의미한다.  
따라서 배낭 문제에서와 같이 전체 비용값의 합 sum부터 1까지 앱의 개수만큼 iteration하며 i번째 앱을 비활성화 시켰을때와 시키지 않았을때의 비용의 총합을 비교하며 dp배열을 초기화한다.  
iteration이 끝나면 다시 dp배열을 1부터 순회한다.  
이때 m보다 크거나 같은 값이 처음으로 나타나는 index가 m만큼의 메모리를 확보하기 위해 필요한 최소 비용이다.  
  
## Source Code
``` cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, sum = 0;
int arr[101];
int v[101];
int dp[10001];

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
		sum += v[i];
  }
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= 1; j--) {
			if (j - v[i] >= 0) {
				dp[j] = max(dp[j], dp[j-v[i]] + arr[i]);
			}
		}
	}

	int i;
	for (i = 1; i < sum && dp[i] < m; i++);
	cout << i << '\n';
}

int main() {
	input();
	solve();

  return 0;
}
```
  
[acmicpc.net/problem/7579]: https://acmicpc.net/problem/7579
[12865번 문제]: https://github.com/RudyPark3091/ps-solutions/tree/master/cpp/12865
