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
//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
//
//请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
//
//如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
//
//示例 1：
//
//输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
//
//输出：4
//
//解释：最多有 5 个 0 和 3 个 1 的最大子集是{ "10","0001","1","0" } ，因此答案是 4 。 
//其他满足题意但较小的子集包括{ "0001","1" } 和{ "10","1","0" } 。{ "111001" } 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs)  //遍历物品
        {
            int zeroNums = 0; int oneNums = 0;
            for (char c : str)
            {
                if (c == '0') zeroNums++;
                else oneNums++;
            }
            //遍历二维背包 后序遍历
            for (int i = m; i >= zeroNums; i--)
            {
                for (int j = n; j >= oneNums; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNums][j - oneNums] + 1);
                    //字符串的zeroNum和oneNum相当于物品的重量（weight[i]）
                    //dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                }
            }
        }
        return dp[m][n];
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
    vector<string> g = { "10", "0001", "111001", "1", "0" };
    TreeNode* root = NULL;
    int res = obj->findMaxForm(g, 5,3);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}