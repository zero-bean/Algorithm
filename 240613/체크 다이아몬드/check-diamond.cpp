#include <iostream>

using namespace std;

void drawDiamond(int size) {
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i + 1; j--)
            cout << " ";
        for (int k = 0; k < i + 1; k++)
            cout << "* ";
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int k = n; k > i; k--)
            cout << "* ";
        cout << endl;
    }
}

int main()
{
    int n;

    cin >> n;

    drawDiamond(n);
}