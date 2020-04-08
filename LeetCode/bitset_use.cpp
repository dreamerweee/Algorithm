/*
* 有40亿个整数，再给一个新的整数，判断新的整数是否在这40亿个整数中
* bitmap 的思想
*/

#include <iostream>
#include <bitset>

using namespace std;

const int kMaxBitSize = 1000;

int main(void)
{
    bitset<kMaxBitSize> bit_map;
    bit_map.set();
    bit_map.reset(10);
    int key;
    cin >> key;
    if (bit_map.test(key)) {
        cout << "find" << endl;
    } else {
        cout << "not find" << endl;
    }
    
    return 0;
}