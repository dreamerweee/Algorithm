/*
* 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
* 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
* 你从其中的一个加油站出发，开始时油箱为空。
* 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
* 说明: 
*   如果题目有解，该答案即为唯一答案。
*   输入数组均为非空数组，且长度相同。
*   输入数组中的元素均为非负数。
*/

/*
* 贪心算法思想：从加油站能满足前往下一站的最小油耗站出发
*/
int CanCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int start_idx = -1;
    int len = gas.size();
    int cost_len = len;
    int min_cost = INT_MAX;
    int left_gas = 0;
    for (int i = 0; i < len; ++i) {
        if (left_gas + gas[i] >= cost[i] && cost[i] < min_cost) {
            left_gas = left_gas + gas[i] - cost[i];
            min_cost = cost[i];
            start_idx = i;
        } else if (left_gas + gas[i] < cost[i]) {
            left_gas = 0;
            min_cost = INT_MAX;
        }
    }

    if (start_idx == -1) {
        return -1;
    }

    // 验证是否可以绕行一圈
    left_gas = 0;
    int ret_idx = start_idx;
    while (len--) {
        if (start_idx == cost_len) {
            start_idx = 0;
        }
        left_gas = left_gas + gas[start_idx] - cost[start_idx];
        ++start_idx;
    }
    if (left_gas < 0) {
        ret_idx = -1;
    }
    return ret_idx;
}
