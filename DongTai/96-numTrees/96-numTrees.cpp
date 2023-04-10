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
//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
class Solution {
public:
    //dp[i] 表示  1到i为节点的二叉搜索数的个数
    //递推公式 dp[i] += dp[j-1] * dp[i-j]   j=1 j<=i j++
    //dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]
    //dp[0] = dp[1] = 1

    //规律可看出  
    // n=3个节点 ： 1为节点 左子树节点数量1-1=0 右子树数量n-1=2  dp[0]*dp[2] = 1*2=2
    //              2为节点 左子树节点数量2-1=1 右子树数量n-2=1  dp[1]*dp[2] = 1*1=1
    //              3为节点 左子树节点数量3-1=2 右子树数量n-3=0  dp[2]*dp[0] = 2*1=2
    //最小单元是 dp[0] = dp[1] = 1    dp[2] = 2

    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
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
    vector<vector<int>> obstacleGrid = { {0, 0, 0},{0, 1, 0},{0, 0, 0} };
    int res = obj->numTrees(3);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}