#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Person
{
    Person(const int inStart, const int inEnd) : start(inStart), end(inEnd) {}
    Person() {}

    bool operator<(const Person& other) const { return start > other.start; }

    int start = 0;
    int end = 0;
};

priority_queue<Person, vector<Person>> People{};
int N = 0;

void Solve()
{
    // pair.first == 종료 시간, pair.second == 자리 번호
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> output(cmp);
    priority_queue<int, vector<int>, greater<int>> freeSeats;

    vector<int> counts(N, 0);
    int maxSeatIdx = 0;

    while (!People.empty())
    {
        Person personEntering = People.top();
        People.pop();

        while (!output.empty() && output.top().first <= personEntering.start)
        {
            freeSeats.push(output.top().second); // 사용 끝난 자리 번호를 추가
            output.pop();
        }

        int targetSeat;
        if (freeSeats.empty())
        {
            // 비어 있는 자리가 없으면 새로운 번호 부여
            targetSeat = maxSeatIdx++;
        }
        else
        {
            // 비어 있는 자리 중 가장 번호가 작은 것 선택
            targetSeat = freeSeats.top();
            freeSeats.pop();
        }

        output.push({ personEntering.end, targetSeat });
        counts[targetSeat]++;
    }

    cout << maxSeatIdx << "\n";
    for (int i = 0; i < maxSeatIdx; ++i)
    {
        cout << counts[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int s, e;
        cin >> s >> e;
        People.push(Person(s, e));
    }

    Solve();

    return 0;
}