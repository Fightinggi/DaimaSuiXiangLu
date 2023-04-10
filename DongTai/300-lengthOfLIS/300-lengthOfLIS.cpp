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
//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//
//子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3, 6, 2, 7] 是数组[0, 3, 1, 6, 2, 2, 7] 的子序列。
//
//示例 1：
//
//输入：nums = [10, 9, 2, 5, 3, 7, 101, 18]
//输出：4
//解释：最长递增子序列是[2, 3, 7, 101]，因此长度为 4 。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        //1.定义dp[i]数组 表示 i 之前包括 i 得以nums[i]结尾的最长递归子序列长度
        //2.递推公式：if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)
        //dp[j] 表示从0到i-1 最长递归子序列长度
        //初始化 dp[i]=1;
        int len = nums.size();
        if (len <= 1) return nums.size();
        int res = 0;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > res) res = dp[i];
        }
        return res;
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
    vector<int> g2 = { 7,1,5,3,6,4 };
    string s = "leetcode";
    int res = obj->lengthOfLIS(g2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}