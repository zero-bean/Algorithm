#include <iostream>

using namespace std;

void drawDiamond(int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = size; j > i + 1; j--)
            cout << " ";
        for (int k = 0; k < i + 1; k++)
            cout << "* ";
        cout << endl;
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int k = size; k > i; k--)
            cout << "* ";
        cout << endl;
    }
}

int main()
{
    int n;

    cin >> n;

    drawDiamond(n);

    return 0;
}