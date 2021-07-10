## Problem
[acmicpc.net/problem/10942]  
  
## Example
input ->  
7  
1 2 1 3 1 2 1  
4  
1 3  
2 5  
3 3  
5 7  
  
output ->  
1  
0  
1  
1  
  
## Logic
이 문제는 배열의 해당 부분집합이 팰린드롬인지 판단하는 문제이다.  
제한시간이 0.5초라 단순 반복으로 해결할 수 없는 문제이다.  
총 검사의 수가 최대 1,000,000회이고, 검사마다 반복을 한다면 시간초과가 나기 때문이다.  
이를 해결하기 위해 메모이제이션 기법을 이용한다.  
`수열의 길이 * 수열의 길이`만큼의 dp배열을 선언하고, 미리 해당 수열이 팰린드롬인지 검사한다.  
이때 dp[i][j] 의 값이 1이라면 i번째부터 j번째까지의 수열이 팰린드롬이고, 0이라면 팰린드롬이 아님을 의미한다.  
dp[i][i]는 수열의 길이가 1이므로 항상 팰린드롬이다.  
어떤 팰린드롬이 있다면 이 팰린드롬 앞 뒤에 같은 수를 붙이면 그 수열 역시 팰린드롬임을 생각한다.  
위 정보를 기반으로 dp배열을 채워나간다.  
먼저 수열을 O(n)으로 순회하여, 길이가 1, 2인 부분수열들에 대해 dp배열을 갱신한다.  
위에서 말했듯 길이가 1인 부분수열은 무조건 팰린드롬이고, 길이가 2인 부분수열은 검사하여 갱신한다.  
다음으로 각 부분수열들에 대해 길이를 늘려가며 이전 dp값을 참조하며 갱신을 시작한다.  
아래 코드에서 r이 부분수열의 길이, i이 왼쪽 인덱스, j이 오른쪽 인덱스에 해당한다.  
dp배열을 모두 갱신하면, 입력을 받는대로 해당하는 dp배열값을 출력해준다.  
  
## Source Code
``` cpp
#include <iostream>
using namespace std;

int n, m;
int arr[2001];
bool dp[2001][2001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int s, e;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	cin >> m;

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		if (arr[i] == arr[i-1]) {
			dp[i-1][i] = 1;
		}
	}

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l; i++) {
			int j = i + l;
			if (arr[i] == arr[j] && dp[i+1][j-1] == 1) {
				dp[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}
```
  
[acmicpc.net/problem/10942]: https://acmicpc.net/problem/10942
