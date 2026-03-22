#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

struct Node
{
	Node(const int inNumber, const bool inIsEnd = false) : number(inNumber), isEnd(inIsEnd) {}

	int number = -1;
	bool isEnd = false;
	vector<shared_ptr<Node>> children{};
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cases = 0;
	cin >> cases;

	while (cases--)
	{
		int n = 0;
		cin >> n;

		vector<string> phoneNumbers(n);
		for (auto& phoneNumber : phoneNumbers)
		{
			cin >> phoneNumber;
		}
		sort(phoneNumbers.begin(), phoneNumbers.end());

		shared_ptr<Node> root = make_shared<Node>(-1);
		bool bIsPrefix = false;

		for (auto& phoneNumber : phoneNumbers)
		{
			if (bIsPrefix)
			{
				break;
			}

			shared_ptr<Node> nxtNode = root;
			const size_t sz = phoneNumber.size() - 1;

			// 하나의 전화번호에 대하여 Trie 구조 구성
			for (int j = 0; !bIsPrefix && j <= sz; ++j)
			{
				bool bIsLastIndex = (j == sz);
				bool bNeedMakeChild = true;

				// 자식을 순회하여, 노드가 존재하는지 검사
				for (shared_ptr<Node>& child : nxtNode->children)
				{
					// 자식이 존재한다면
					if (child->number == phoneNumber[j])
					{
						// 이미 겹치는 전화번호라면 탐색 종료
						if (child->isEnd == true)
						{
							bIsPrefix = true;
							break;
						}
						else
						{
							nxtNode = child;
							bNeedMakeChild = false;
							break;
						}
					}
				}

				if (bNeedMakeChild)
				{
					shared_ptr<Node> child = make_shared<Node>(phoneNumber[j], bIsLastIndex);
					nxtNode->children.push_back(child);
					nxtNode = child;
				}
			}
		}

		cout << (bIsPrefix ? "NO\n" : "YES\n");
	}

	return 0;
}