#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> elements;
    vector<int> ans;
    stack<int> s;

    cin >> N;

    elements.resize(N);
    ans.resize(N);

    for (int i = 0; i < N; i++)
        cin >> elements[i];

    s.push(0);

    for (int i = 1; i < N; i++) {
        while (!s.empty() && elements[i] > elements[s.top()]) {
            ans[s.top()] = elements[i];
            s.pop();
        }
 
        s.push(i);
    }

    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}