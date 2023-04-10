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
//给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//
//注意 : 每个数组中的元素不会超过 100 数组的大小不会超过 200
//
//示例 1 :
//
//    输入 : [1, 5, 11, 5]
//    输出 : true
//    解释 : 数组可以分割成[1, 5, 5] 和[11].
class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sums = 0;
        for (int i = 0; i < nums.size(); i++)
            sums += nums[i];
        if (sums % 2 != 0) return false;
        //01背包问题
        //背包容量sums/2
        //物品重量=物品价值nums[i]
        vector<int> weight(nums);
        vector<int> value(nums);
        int bagWeight = sums / 2;

        //初始化
        vector<int> dp(bagWeight + 1, 0);
        for (int i = 0; i < weight.size(); i++)
        {
            for (int j = bagWeight; j >= weight[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }

        return sums / 2 == dp[bagWeight];

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
    vector<int> g = { 1,5,11,5 };
    TreeNode* root = NULL;
    int res = obj->canPartition(g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}