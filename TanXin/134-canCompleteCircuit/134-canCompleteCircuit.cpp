#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i + 1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//
//如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 - 1。
//示例 1: 输入:
//
//gas = [1, 2, 3, 4, 5]
//cost = [3, 4, 5, 1, 2]
//输出 : 3 解释 :
//
//    从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
//    开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
//    开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
//    开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
//    开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
//    开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
//    因此，3 可为起始索引。
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //暴力求解，模拟从每个加油站跑一圈得过程
        //int index = (index+1)%gas.size();  index∈[0，size()] 代码技巧
        // for(int i=0; i < gas.size(); i++)
        // {
        //     int rest = gas[i] - cost[i];
        //     int index = (i+1)%gas.size();//求余数  5%4 = 1
        //     while(rest>0 && index != i)
        //     {
        //         rest += gas[index] - cost[index];
        //         int index = (index+1)%gas.size();
        //     }
        //     if(rest>=0 && index==i) return i;//绕一圈回来了
        // }
        // return -1;

        int CurSum = 0;
        int TotalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            TotalSum += gas[i] - cost[i];
            CurSum += gas[i] - cost[i];
            if (CurSum < 0) // 当前累加rest[i]和 curSum一旦小于0
            {
                CurSum = 0;   // curSum从0开始
                start = i + 1;// 起始位置更新为i+1
            }
        }
        if (TotalSum < 0) return -1;
        return start;

    }
};
//仿函数 打印一维数组 vector<string>
struct print002 {
    void operator()(string val) {
        cout << val << " ";
    }
};
void print_vector_str(vector<string> res)
{
    for_each(res.begin(), res.end(), print002());
    cout << endl;
}
//打印二维数组
template<typename T>
void PrintVecofVec2(vector<vector<T>>& res) {
    for (auto& rowV : res) {
        for (auto& el : rowV) {
            cout << el << " ";
        }
        cout << "; ";
    }
    cout << endl;
}
void test()
{
    Solution* obj = new Solution();
    vector<int> g = { 1,2,3,4,5 };
    vector<int> s = { 3,4,5,1,2 };

    int res = obj->canCompleteCircuit(g,s);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}