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
//���������ַ��� text1 �� text2�������������ַ���������������еĳ��ȡ�
//
//һ���ַ����� ������ ��ָ����һ���µ��ַ�����������ԭ�ַ����ڲ��ı��ַ������˳��������ɾ��ĳЩ�ַ���Ҳ���Բ�ɾ���κ��ַ�������ɵ����ַ�����
//
//���磬"ace" �� "abcde" �������У��� "aec" ���� "abcde" �������С������ַ����ġ����������С����������ַ�������ͬӵ�е������С�
//
//���������ַ���û�й��������У��򷵻� 0��
//
//ʾ�� 1:
//
//���룺text1 = "abcde", text2 = "ace" �����3 ���ͣ�������������� "ace"�����ĳ���Ϊ 3��
//
//ʾ�� 2 : ���룺text1 = "abc", text2 = "abc" �����3 ���ͣ�������������� "abc"�����ĳ���Ϊ 3��
//
//ʾ�� 3 : ���룺text1 = "abc", text2 = "def" �����0 ���ͣ������ַ���û�й��������У����� 0��
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // ��άdp[i][j]���� 
        // ����Ϊ[0��i-1]��text1  �� ����Ϊ[0��j-1]text2��  �����������
        // ���ƹ�ʽdp[i][j]
        // ��text1[i-1] == text2[j-1]  dp[i][j]����һ�ε������������ dp[i-1][j-1]  �ټ�һ�õ�
        // ��text1[i-1] != text2[j-1]  dp[i][j]����һ�ε������������ dp[i][j-1] ���� dp[i-1][j] ���õ�
        // i��j��1��ʼ��������ʼ��dp[0][j]=dp[i][0]=0
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[text1.size()][text2.size()];
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
    int res = obj->longestCommonSubsequence(text1, text2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}