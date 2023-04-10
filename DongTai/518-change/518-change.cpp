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
//给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。
//
//示例 1:
//
//输入: amount = 5, coins = [1, 2, 5]
//输出 : 4
//解释 : 有四种方式可以凑成总金额 :
//
//    5 = 5
//    5 = 2 + 2 + 1
//    5 = 2 + 1 + 1 + 1
//    5 = 1 + 1 + 1 + 1 + 1
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        //完全背包问题：硬币可重复选择
        //背包容量：总金额amount
        //物品重量：不同面额的硬币conis
        //物品价值：1，求组合数
        //dp[amount]表示选取不同面额的硬币conis，装满总金额amount的组合数
        //递推公式：dp[j] = max(dp[j], dp[j-conis[i]]+1)   ; return dp[amount]
        //遍历顺序  物品  背包  正序遍历

        int bagSize = amount;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= bagSize; j++)  //正序遍历
            {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[bagSize];
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
    vector<int> g = {1,2,5};
    TreeNode* root = NULL;
    int res = obj->change(5, g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}