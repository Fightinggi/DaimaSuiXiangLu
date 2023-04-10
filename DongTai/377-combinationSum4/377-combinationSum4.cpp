#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。
//
//示例 :
//
//nums = [1, 2, 3]
//target = 4
//所有可能的组合为：(1, 1, 1, 1) (1, 1, 2) (1, 2, 1) (1, 3) (2, 1, 1) (2, 2) (3, 1)
//
//请注意，顺序不同的序列被视作不同的组合。
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        //完全背包问题
        // 顺序不同的序列被视作不同的组合。求排列
        //求排列数 ① dp[j] += dp[j-nums[i]];  ② 先遍历背包再遍历物品
        //求组合数 ① dp[j] += dp[j-nums[i]];  ② 先遍历物品再遍历背包
        //dp[j] = dp[j] + dp[j-nums[i]] 盛满j容量大小大背包 得最大组合数 return dp[target];
        //正向遍历  初始化
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++)  //背包
        {
            for (int i = 0; i < nums.size(); i++)  //物品
            {
                //C++测试用例有两个数相加超过int的数据，所以需要在if里加上dp[i] < INT_MAX - dp[i - num]。
                if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])
                    dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
//仿函数 打印一维数组 vector<string>
template<typename T>
struct print002 {
    void operator()(T val) {
        cout << val << " ";
    }
};
template<typename T>
void print_vector_str(vector<T> res)
{
    for_each(res.begin(), res.end(), print002<T>());
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
    vector<int> g = { 1,2,5 };
    TreeNode* root = NULL;
    int res = obj->combinationSum4(g,5);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}