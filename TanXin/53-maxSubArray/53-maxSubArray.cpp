#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//示例 :
//
//输入: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//输出 : 6
//解释 : 连续子数组[4, -1, 2, 1] 的和最大，为 6
using namespace std;
class Solution {
public:
    //-2,1,-3,4,-1,2,1,-5,4
    //连续和是正数  是局部最优的
    int maxSubArray(vector<int>& nums) {

        int res = INT32_MIN;
        int count = 0;//连续和
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];  //计算连续和
            if (count > res)   res = count;  // 取区间累计的最大值（相当于不断确定最大子序终止位置）
            if (count <= 0)  count = 0; //重新开始计算连续和，和为负，对后面的数只有减小的作用。
                
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
    vector<int> g = { -2,1,-3,4,-1,2,1,-5,4 };

    int res = obj->maxSubArray(g);
    cout << res <<  endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}