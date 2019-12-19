#include <iostream>

using namespace std;

int g_queens[8];
int g_sum = 0;

void ShowResult()
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (g_queens[i] == j) {
                cout << "Q ";
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
    cout << endl;
    ++g_sum;
}

bool Check(int row, int column)
{
    int left = column - 1;
    int right = column + 1;
    for (int i = row - 1; i >= 0; --i) {
        if (g_queens[i] == column) {
            return false;
        }
        if (left >= 0 && g_queens[i] == left) {
            return false;
        }
        if (right < 8 && g_queens[i] == right) {
            return false;
        }
        --left;
        ++right;
    }
    return true;
}

void Calc8Queens(int row)
{
    if (row == 8) {
        ShowResult();
        return;
    }
    for (int column = 0; column < 8; ++column) {
        g_queens[row] = column;
        if (Check(row, column)) {
            Calc8Queens(row + 1);
        }
    }
}

int main()
{
    Calc8Queens(0);
    cout << "g_sum = " << g_sum << endl;
    return 0;
}