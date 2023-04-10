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
//����һ���ַ��� s ���ҵ�������Ļ��������У������ظ����еĳ��ȡ����Լ��� s ����󳤶�Ϊ 1000 ��
//
//ʾ�� 1: ����: "bbbab" ��� : 4 һ�����ܵ������������Ϊ "bbbb"��
//
//ʾ�� 2 : ���� : "cbbd" ��� : 2 һ�����ܵ������������Ϊ "bb"��
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.size(); j++)  // �Խ����ѳ�ʼ����Ϊ 1 ��i=jʱdp[i][j] = 1 ����һ�п�ʼ��伴��
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2; //����һ��dp, ���������˵�ֵ
                }
                else
                {
                    //ԭ���� dp[i+1][j-1]  Ҫ�ﵽ dp[i][j]
                    //dp[i+1][j]  ��ʾ�������s[j];  dp[i][j-1]  ��ʾ�����Ҷ�s[i]  
                    //�ֱ����s[i]��s[j]������һ�����������Ļ���������
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];  //���Ͻ�
    }
};

//�º��� ��ӡһά���� vector<string>
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
//��ӡ��ά����
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