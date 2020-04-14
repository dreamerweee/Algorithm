// 数字华容道问题
// 深度优先搜索  dfs

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 移动的方向
enum Direction {LEFT = 1, RIGHT, UP, DOWN};
// 3*3的数字盘
vector<vector<int>> arr(3, vector<int>(3));
// 记录当前空格子的位置
int x, y;
// 正确的状态
const int correct_state = 123456780;
// 记录已搜索过的状态
set<int> exist_states;
// 记录格子路径
vector<int> move_arr;

// 获取当前状态
int GetState()
{
    int state = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            state = state * 10 + arr[i][j];
        }
    }
    return state;
}

// 初始化数字盘
void Init()
{
    int val;
    int i = 0, j = 0;
    while (cin >> val) {
        arr[i][j] = val;
        ++j;
        if (j == 3) {
            ++i;
            j = 0;
        }
        if (i == 3){
            break;
        }
    }
}

// 打印
void Print()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 查找空格子的位置
void FindPosition()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (arr[i][j] == 0) {
                x = i;
                y = j;
                return;
            }
        }
    }
    throw runtime_error("Not find space position.");
}

// 检查能否移动
bool CanMove(Direction dir)
{
    switch (dir) {
        case LEFT:
            return y > 0;
        case RIGHT:
            return y < 2;
        case UP:
            return x > 0;
        case DOWN:
            return x < 2;
    }
}

void Move(Direction dir)
{
    switch (dir) {
        case LEFT:
            arr[x][y] = arr[x][y-1];
            arr[x][y-1] = 0;
            --y;
            break;
        case RIGHT:
            arr[x][y] = arr[x][y+1];
            arr[x][y+1] = 0;
            ++y;
            break;
        case UP:
            arr[x][y] = arr[x-1][y];
            arr[x-1][y] = 0;
            --x;
            break;
        case DOWN:
            arr[x][y] = arr[x+1][y];
            arr[x+1][y] = 0;
            ++x;
            break;
    }
    move_arr.push_back(dir);
}

// 回退
void MoveBack(Direction dir)
{
    switch (dir) {
        case LEFT:
            arr[x][y] = arr[x][y+1];
            arr[x][y+1] = 0;
            ++y;
            break;
        case RIGHT:
            arr[x][y] = arr[x][y-1];
            arr[x][y-1] = 0;
            --y;
            break;
        case UP:
            arr[x][y] = arr[x+1][y];
            arr[x+1][y] = 0;
            ++x;
            break;
        case DOWN:
            arr[x][y] = arr[x-1][y];
            arr[x-1][y] = 0;
            --x;
            break;
    }
    move_arr.pop_back();
}

bool Search(Direction dir)
{
    if (move_arr.size() > 100) {
        return false;
    }
    if (CanMove(dir)) {
        Move(dir);
        int state = GetState();
        if (state == correct_state) {
            return true;
        }
        if (exist_states.find(state) != exist_states.end()) {
            MoveBack(dir);
            return false;
        }
        exist_states.insert(state);
        bool res = Search(RIGHT) || Search(DOWN) || Search(LEFT) || Search(UP);
        if (res) {
            return true;
        } else {
            MoveBack(dir);
            return false;
        }
    }
    return false;
}

bool Solve()
{
    int state = GetState();
    if (state == correct_state) {
        return true;
    }
    // 记录初始状态
    exist_states.insert(state);
    return Search(RIGHT) || Search(DOWN) || Search(LEFT) || Search(UP);
}

void PrintMove()
{
    for (int i = 0; i < move_arr.size(); ++i) {
        cout << move_arr[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    Init();
    Print();
    FindPosition();
    cout << "==================== begin: " << endl;
    if (Solve()) {
        cout << "the answer is: " << endl;
        Print();
        cout << "move direction: ";
        PrintMove();
    } else {
        cout << "not find solution." << endl;
    }
    return 0;
}
