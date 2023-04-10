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
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//
//问总共有多少条不同的路径？
//示例 2：
//
//输入：m = 2, n = 3
//输出：3
//解释： 从左上角开始，总共有 3 条路径可以到达右下角。
//
//向右->向右->向下
//向右->向下->向右
//向下->向右->向右
class Solution {
public:
    int uniquePaths(int m, int n) {

        //dp[i][j]表示从(0,0)到(i,j)有多少条路径
        //递推公式：dp[i][j] = dp[i-1][j] + dp[i][j-1]  向下或者向右移动一步
        //初始化第一行到底 和 第一列到底 只有一种路径 所以dp[0][j] + dp[i][0]初始化为1
        //遍历顺序，i,j分别从前向后

        //定义二维数组  保存dp(i,j)两个坐标得状态
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int raw = 0; raw < m; raw++) dp[raw][0] = 1;
        for (int rol = 0; rol < n; rol++) dp[0][rol] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
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
    vector<int> g = { 2,3,1,1,4 };
    TreeNode* root = NULL;
    int res = obj->uniquePaths(4,3);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}