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
//给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
//
//字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
//（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
class Solution {
public:
    int numDistinct(string s, string t) {

        // dp[i][j] 表示长度为0到s.size()-1 的序列s  能构成 多少个长度为0到t.size()-1 的序列s
        // 以i-1为结尾的s子序列中 出现 以j-1为结尾的t的个数为dp[i][j]。
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));

        //初始化
        //t为空串  s[i][0] = 1;
        //s为空串  s[0][j] = 0;
        for (int i = 0; i < s.size(); i++)
            dp[i][0] = 1;
        for (int j = 1; j < t.size(); j++)
            dp[0][j] = 0;

        //递推公式：相等 / 不相等
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                // 题意是从s中找 可以删除s
                //相等情况下dp[i][j]由dp[i-1][j-1]和删除s尾元素的dp值
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];  //保持s上一位的

            }
        }
        return dp[s.size()][t.size()];
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
    string text1 = "abcde";
    string text2 = "ace";
    int res = obj->numDistinct(text1, text2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}