#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 
//除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
//如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//
//计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
class Solution {
public:

    vector<int> robtree(TreeNode* cur)
    {
        if (cur == NULL) return { 0, 0 };
        vector<int> left_dp = robtree(cur->left);
        vector<int> right_dp = robtree(cur->right);
        //不偷当前节点 可以偷左右子节点dp得最大值得和。
        int val0 = max(left_dp[0], left_dp[1]) + max(right_dp[0], right_dp[1]);
        //偷当前节点 dp[1]就等于当前节点的值+左右子节点dp[0]不偷得值。
        int val1 = cur->val + left_dp[0] + right_dp[0];;
        return { val0, val1 };
    }

    int rob(TreeNode* root) {

        vector<int> dp = robtree(root);
        return max(dp[0], dp[1]);  //返回偷/不偷根节点得最大值
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
    vector<string> g = { "leet", "code" };
    vector<int> g2 = { 1,2,3,1 };
    string s = "leetcode";
    int res = obj->rob(g2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}