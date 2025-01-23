#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct jewelry {
public:
    jewelry() : weight(0), price(0) {};
    jewelry(const jewelry& j) : weight(j.weight), price(j.price) {};

public:
    int weight;
    int price;
};

vector<jewelry> jewelries;
vector<int> limited;
int N, K;

void Solve() {
    auto cmp = [&](const jewelry& j1, const jewelry& j2) {return j1.price < j2.price; };
    priority_queue<jewelry, vector<jewelry>, decltype(cmp)> pq(cmp);
    int idx = 0;
    long long tot = 0;

    for (const int& bag : limited) {
        while (idx < N && bag >= jewelries[idx].weight) {
            pq.push(jewelries[idx]);
            idx++;
        }

        if (!pq.empty()) {
            tot += static_cast<long long>(pq.top().price);
            pq.pop();
        }
    }

    cout << tot << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    jewelries = vector<jewelry>(N);
    limited = vector<int>(K);

    for (int i = 0; i < N; i++)
        cin >> jewelries[i].weight >> jewelries[i].price;

    for (int i = 0; i < K; i++)
        cin >> limited[i];

    sort(jewelries.begin(), jewelries.end(), [&](const jewelry& a, const jewelry& b) {return a.weight < b.weight; });
    sort(limited.begin(), limited.end(), [&](const int& a, const int& b) {return a < b; });

    Solve();

    return 0;
}
