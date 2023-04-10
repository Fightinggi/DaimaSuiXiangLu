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
//有一堆石头，每块石头的重量都是正整数。
//
//每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
//
//如果 x == y，那么两块石头都会被完全粉碎；
//
//如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y - x。
//
//最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
//
//示例：
//
//输入：[2, 7, 4, 1, 8, 1]
//输出：1
//解释：
//
//组合 2 和 4，得到 2，所以数组转化为[2, 7, 1, 8, 1]，
//组合 7 和 8，得到 1，所以数组转化为[2, 1, 1, 1]，
//组合 2 和 1，得到 1，所以数组转化为[1, 1, 1]，
//组合 1 和 1，得到 0，所以数组转化为[1]，这就是最优值。
class Solution {
public:

    int lastStoneWeightII(vector<int>& stones) {
        int sums = 0;
        for (int i = 0; i < stones.size(); i++)
            sums += stones[i];

        //01背包问题
        //背包容量sums/2
        //物品重量=物品价值nums[i]
        vector<int> weight(stones);
        vector<int> value(stones);
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

        return sums - 2 * dp[bagWeight];

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
    vector<int> g = { 2,7,4,1,8,1 };
    TreeNode* root = NULL;
    int res = obj->lastStoneWeightII(g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}