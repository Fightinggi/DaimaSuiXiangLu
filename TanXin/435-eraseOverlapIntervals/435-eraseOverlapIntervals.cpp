#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
//
//注意 : 可以认为区间的终点总是大于它的起点。 区间[1, 2] 和[2, 3] 的边界相互“接触”，但没有相互重叠。
//
//示例 1 :
//
//    输入 : [[1, 2], [2, 3], [3, 4], [1, 3]]
//    输出 : 1
//    解释 : 移除[1, 3] 后，剩下的区间没有重叠。
class Solution {
public:

    //计算有几组重叠区间，区间数-重叠区间组数 = 需要移除区间的最小数量
    //保证 连续重叠区间只有一个区间，其余的都不要

    //右边界排序 从小到大
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int end = intervals[0][1]; //记录第一个右边界  
        for (int i = 1; i < intervals.size(); i++)
        {
            //判断是否重叠,没有重叠，重叠区间组数加1,重新设定最小右边界
            // if(end <= intervals[i][0])
            // {
            //     end = intervals[i][1];  //更新最小右边界
            //     count++;//计算
            // }
            if (intervals[i - 1][1] <= intervals[i][0])
            {
                count++;
            }
            else
            {
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }
        return intervals.size() - count;

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
    vector<int> g = { 5,5,5,10,20 };
    vector<vector<int>> people = { {1,2} ,{2,3},{3,4},{1,3} };
    int res = obj->eraseOverlapIntervals(people);
    cout << res << endl;
    //PrintVecofVec2(res);

}
int main()
{
    test();
    return 0;
}