#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//给出一个区间的集合，请合并所有重叠的区间。
//
//示例 1:
//
//输入: intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
//输出 : [[1, 6], [8, 10], [15, 18]]
//解释 : 区间[1, 3] 和[2, 6] 重叠, 将它们合并为[1, 6].
using namespace std;
class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //左边界从小到大排序
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] >= intervals[i][0])  //有重叠区间
            {
                //更新最右边界
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else //无重叠 放入下一组重叠区间
            {
                res.push_back(intervals[i]);
            }
        }
        return res;

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
    vector<int> g = { 1,2 };
    vector<vector<int>> people = { {1,3} ,{2,6},{8,10},{15,18} };
    vector<vector<int>> res = obj->merge(people);
    //cout << res << endl;
    PrintVecofVec2(res);

}
int main()
{
    test();
    return 0;
}