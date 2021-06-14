#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int ans = 0;
	int n = scoville.size();
	priority_queue<int, vector<int>, greater<int>> heap;
	for (auto item : scoville) heap.push(item);

	while (heap.size() > 1 && heap.top() < K) {
		ans++;
		int fst = heap.top();
		heap.pop();
		int snd = heap.top();
		heap.pop();
		heap.push(fst + snd * 2);
	}
	return heap.top() < K ? -1 : ans;
}

int main() {
	cout << solution({1, 2, 3, 9, 10, 12}, 7) << endl;
	return 0;
}
