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
//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
//说明：
//
//拆分时可以重复使用字典中的单词。
//
//你可以假设字典中没有重复的单词。
//
//示例 1：
//
//输入 : s = "leetcode", wordDict = ["leet", "code"]
//输出 : true
//解释 : 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        //完全背包问题
        //背包容量  字符串j长度
        //物品重量  字典中的单词大小
        //排列数  结果对顺序有要求
        // dp[i] : 字符串长度为i的话，dp[i]为true，表示可以拆分为一个或多个在字典中出现的单词。

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int j = 1; j <= s.size(); j++)  //背包
        {
            for (int i = 0; i < j; i++)  //物品
            {
                string word = s.substr(i, j - i); //substr(起始位置，截取的个数)  物品
                if (dp[i] == true && wordSet.find(word) != wordSet.end())
                    dp[j] = true;
            }
        }
        return dp[s.size()];
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
    vector<string> g = { "leet", "code"};
    string s = "leetcode";
    int res = obj->wordBreak(s, g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}