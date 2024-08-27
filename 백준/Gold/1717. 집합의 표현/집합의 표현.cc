#include <iostream>
#include <vector>

using namespace std;

int find_Elements(vector<int>& v, int a) {
    if (v[a] != a) {
        v[a] = find_Elements(v, v[a]);
    }
    return v[a];
}

void union_Elements(vector<int>& v, int a, int b) {
    if (a == b)
        return;

    int rootA = find_Elements(v, a);
    int rootB = find_Elements(v, b);

    rootA < rootB ? v[rootB] = rootA : v[rootA] = rootB;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> elements(n + 1);

    for (int i = 0; i < n + 1; i++)
        elements[i] = i;

    while (m--) {
        int cal, a, b;

        cin >> cal >> a >> b;

        if (cal == 1)
            find_Elements(elements, a) == find_Elements(elements, b) ? printf("YES\n") : printf("NO\n");
        else if (cal == 0)
            union_Elements(elements, a, b);
    }

    return 0;
}