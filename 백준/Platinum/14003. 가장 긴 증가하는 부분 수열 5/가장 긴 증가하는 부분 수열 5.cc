#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int n;

int Binary_Search_UB(vector<int>& d, int target) {
    int left = 0;
    int right = d.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (d[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }

    return right;
}

void Solve() {
    vector<int> DP;  
    vector<int> prev(n, -1); 
    vector<int> last_idx;  

    DP.push_back(vec[0]);
    last_idx.push_back(0);

    for (int i = 1; i < n; i++) {
        if (DP.back() < vec[i]) {
            prev[i] = last_idx.back(); 
            DP.push_back(vec[i]);
            last_idx.push_back(i);
        }
        else {
            int selected = Binary_Search_UB(DP, vec[i]);
            if (DP[selected] != vec[i]) {
                DP[selected] = vec[i];
                last_idx[selected] = i; 
                prev[i] = (selected > 0) ? last_idx[selected - 1] : -1;
            }
        }
    }

    vector<int> result;
    for (int i = last_idx.back(); i != -1; i = prev[i])
        result.push_back(vec[i]);

    reverse(result.begin(), result.end());

    cout << result.size() << endl;
    for (const auto& e : result)
        cout << e << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
    }

    Solve();

    return 0;
}