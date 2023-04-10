#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//给定一个非负整数数组，你最初位于数组的第一个位置。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//判断你是否能够到达最后一个位置。
//
//示例 1:
//
//输入: [2, 3, 1, 1, 4]
//输出 : true
//解释 : 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
using namespace std;
class Solution {
public:
    // 贪心算法局部最优解：每次取最大跳跃步数（取最大覆盖范围），整体最优解：最后得到整体最大覆盖范围，看是否能到终点。
    // 不纠结于跳几步：题目限制--数组中的每个元素代表你在该位置可以跳跃的最大长度。只要最大长度能覆盖终点就能跳到.
    

    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        int count = 0; //记录第i位置覆盖范围
        int i = 0;
        for (; i <= count; i++)
        {
            count = max(count, i + nums[i]);  //i+nums[i] 第i位置能覆盖到的位置
            if (count >= nums.size() - 1) return true;//覆盖范围能覆盖到最后一个元素位置就返回true 
        }
        return false;
    }
};
// 1、如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点
// 2、可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新
// 3、如果可以一直跳到最后，就成功了
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;//记录能到的最远下标
        for (int i = 0; i < nums.size(); i++) {
            if (k < i) return false;//判断维护的能到最远下标  能否包含i
            k = max(k, i + nums[i]);//维护一个能到最远下标的数  先判断的话  max不包括最后一个数
        }
        return true;
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
    vector<int> g = { 2,3,1,1,4 };

    bool res = obj->canJump(g);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}