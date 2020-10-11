## Problem
[귀찮으니까 링크로 대체]  
   
## Example
input ->   
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
   
output -> 
4   
   
## Logic Flow   
이 문제의 키는 정렬이다.   
하지만 회의 시작시간을 기준으로 정렬하면 안된다.   
1 10, 2 5, 6 8 과 같은 입력이 있을 때 1 10을 취하게 되면 뒤 2개의 회의를 취할 수 있음에도 최대 회의를 수용하지 못하기 때문이다.   
따라서 회의 종료시간을 기준으로 정렬한 뒤, 같은 종료시간이면 회의 시작시간을 기준으로 정렬한다.   
첫번째 기준은 종료시간 오름차순, 두번째 기준은 시작시간 내림차순으로 정렬하는 것이다.   
이 문제는 제한시간이 2초에 N = 100,000인 문제이므로 O(NlogN)의 정렬 알고리즘을 사용해야 할것이다.   
C++을 기준으로 <algorithm>에 선언된 sort()함수를 사용한다.   
sort()함수는 세 번째 인자로 함수를 선언받아 정렬조건을 설정할 수 있는데 그에 관련한 사항은 [여기에] 잘 설명되어 있다.   
기준에 따라 정렬해준 뒤 첫번째 회의를 취한다.   
현재 선택한 회의가 끝나는 시간 이후에 시작되는 회의의 숫자를 세고 그 수를 출력한다.   

## Source Code   
``` cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res;
vector<pair<int, int>> arr;

void input() {
  int a, b;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    arr.push_back({a, b});
  }
}

bool comp(pair<int, int> a, pair<int, int> b){
  if(a.second == b.second){
    return a.first < b.first;
  }
  else{
    return a.second < b.second;
  }
}

void solve() {
  sort(arr.begin(), arr.end(), comp);
  int cnt = 1;
  int end = arr[0].second;
  for (int i = 1; i < n; i++) {
    if (end <= arr[i].first) {
      cnt++;
      end = arr[i].second;
    }
  }
  res = cnt;
}

int main() {
  input();
  solve();
  cout << res << '\n';
  return 0;
}
```
   
## Review   
정말 어이없게도 정렬하기전에 cnt와 end변수를 선언해 계속 틀렸다.   
똑같은 논리를 전개하는 코드를 받아와 제출했을때 통과하는것을 보고도 뭐가 잘못됐는지 찾아내기까지 오랜 시간이 걸렸다.   
아직 갈길이 멀다.   
   

[귀찮으니까 링크로 대체]: acmicpc.net/problem/1931
[여기에]: https://modoocode.com/272
