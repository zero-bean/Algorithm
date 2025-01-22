#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap; // 중간값 이상
priority_queue<int, vector<int>, less<int>> maxHeap; // 중간값 이하
int N;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    while (N--) {
        int num;
        cin >> num;
        
        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
        }
        else if (maxHeap.size() == minHeap.size() + 1) {
            minHeap.push(num);
        }

        if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            int e1 = minHeap.top();
            int e2 = maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
            maxHeap.push(e1);
            minHeap.push(e2);
        }

        cout << maxHeap.top() << "\n";
    }

    return 0;
}