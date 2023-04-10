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
//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 - 1。
//
//你可以认为每种硬币的数量是无限的。
//
//示例 1：
//
//输入：coins = [1, 2, 5], amount = 11
//输出：3
//解释：11 = 5 + 5 + 1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        //完全背包问题  背包从前往后遍历
        //不是求组合/排列数，而是子集得大小，即物品价值为1时，容量为j得背包装得物品数量。
        // dp[j] = min(dp[j], dp[j-coins[i]] + 1)   dp[j]：凑足总额为j所需钱币的最少个数为dp[j]
        //参考一和零  求子集大小  value[i] = 1
        //遍历顺序 先物品 再背包
        //初始化：  求最大max  初始化 均为最小值0
        //          求最小min  初始化 均为最大值INT_MAX
        vector<int> dp(amount + 1, INT_MAX);  //背包容量
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) // 物品
        {
            for (int j = coins[i]; j <= amount; j++)  //背包
            {
                if (dp[j - coins[i]] != INT_MAX) // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
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
    int res = obj->combinationSum4(5, g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}