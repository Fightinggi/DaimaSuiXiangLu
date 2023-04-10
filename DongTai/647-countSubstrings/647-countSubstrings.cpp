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
//给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
//
//具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
//
//示例 1：
//
//输入："abc"
//输出：3
//解释：三个回文子串 : "a", "b", "c"
class Solution {
public:
    //dp[i][j] 表示区间i到j区间的子串是否为回文子串，
    //递推公式
    // 1. s[i]与s[j]不相等时，dp[i][j] = false;
    // 2, s[i]与s[j]相等时, i j 间距小于等于1  dp[i][j] = true;
    //                      i j 间距大于1 dp[i][j] = dp[i+1][j-1]
    //初始化均为false
    //遍历顺序  下到上 左到右 dp[i][j] = dp[i+1][j-1]
    //填充 右上角  j 一定大于 i
    int countSubstrings(string s) {

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1) {
                        res++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1]) {
                        res++;
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
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
    string text1 = "abcde";
    string text2 = "ace";
    int res = obj->countSubstrings(text2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}