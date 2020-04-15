// 数字华容道
// 广度优先搜索 bfs

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <set>

using namespace std;

enum Direction {LEFT = 1, RIGHT, UP, DOWN};

const int kCorrectStatus = 123456780;

set<int> exist_status;

// 该结构体用于保存每次的状态
struct Status {
    vector<vector<int>> arr;
    list<int> search_lst;
    int x;
    int y;
    bool find_flag;
    Status() = default;
    Status(vector<vector<int>> _arr, int _x, int _y)
    {
        arr = _arr;
        x = _x;
        y = _y;
    }
    Status(vector<vector<int>> _arr, int _x, int _y, list<int> lst, int _dir)
    {
        arr = _arr;
        x = _x;
        y = _y;
        find_flag = false;
        search_lst = lst;
        search_lst.push_back(_dir);
    }
};

// 获取当前状态
int GetStatus(const vector<vector<int>> &arr)
{
    int status = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            status = status * 10 + arr[i][j];
        }
    }
    return status;
}

bool CanMove(Direction dir, int x, int y)
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
    return false;
}

vector<vector<int>> Move(vector<vector<int>> arr, Direction dir, int &x, int &y)
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
    return arr;
}

Direction GetReverseDir(Direction dir)
{
    switch (dir) {
        case LEFT:
            return RIGHT;
        case RIGHT:
            return LEFT;
        case UP:
            return DOWN;
        case DOWN:
            return UP;
    }
}

// 初始化数字盘
void Init(vector<vector<int>> &arr)
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
void Print(const vector<vector<int>> &arr)
{
    cout << "current array:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 查找空格子的位置
void FindPosition(const vector<vector<int>> &arr, int &x, int &y)
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

string GetDirName(int dir)
{
    switch (dir) {
        case LEFT:
            return "L";
        case RIGHT:
            return "R";
        case UP:
            return "U";
        case DOWN:
            return "D";
    }
}

void PrintMovePath(const list<int> &lst)
{
    cout << "the move path: ";
    auto itr = lst.begin();
    while (itr != lst.end()) {
        cout << GetDirName(*itr++) << " ";
    }
    cout << endl;
}

void CheckMoveAndPush(const Status &status, queue<Status> &que, Direction dir)
{
    int x = status.x;
    int y = status.y;
    if (CanMove(dir, x, y)) {
        vector<vector<int>> new_arr = Move(status.arr, dir, x, y);
        int st = GetStatus(new_arr);
        if (exist_status.find(st) != exist_status.end()) {
            return;
        }
        que.push(Status(new_arr, x, y, status.search_lst, dir));
        exist_status.insert(st);
    }
}

Status Search(const vector<vector<int>> &arr, int x, int y)
{
    queue<Status> status_que;
    Status curr_st(arr, x, y);
    status_que.push(curr_st);
    while (!status_que.empty()) {
        curr_st = status_que.front();
        if (GetStatus(curr_st.arr) == kCorrectStatus) {
            curr_st.find_flag = true;
            return curr_st;
        }
        status_que.pop();
        CheckMoveAndPush(curr_st, status_que, LEFT);
        CheckMoveAndPush(curr_st, status_que, UP);
        CheckMoveAndPush(curr_st, status_que, RIGHT);
        CheckMoveAndPush(curr_st, status_que, DOWN);
    }
    curr_st.find_flag = false;
    return curr_st;
}

int main(void)
{
    vector<vector<int>> arr(3, vector<int>(3));
    Init(arr);
    Print(arr);

    int x, y;
    FindPosition(arr, x, y);
    Status status = Search(arr, x, y);
    if (status.find_flag) {
        cout << "the answer:";
        Print(status.arr);
        PrintMovePath(status.search_lst);
    } else {
        cout << "not find solution." << endl;
    }

    return 0;
}