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
//����һ���ַ��� s ��һ���ַ��� t �������� s ���������� t ���ֵĸ�����
//
//�ַ�����һ�� ������ ��ָ��ͨ��ɾ��һЩ��Ҳ���Բ�ɾ�����ַ��Ҳ�����ʣ���ַ����λ������ɵ����ַ�����
//�����磬"ACE" �� "ABCDE" ��һ�������У��� "AEC" ���ǣ�
class Solution {
public:
    int numDistinct(string s, string t) {

        // dp[i][j] ��ʾ����Ϊ0��s.size()-1 ������s  �ܹ��� ���ٸ�����Ϊ0��t.size()-1 ������s
        // ��i-1Ϊ��β��s�������� ���� ��j-1Ϊ��β��t�ĸ���Ϊdp[i][j]��
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));

        //��ʼ��
        //tΪ�մ�  s[i][0] = 1;
        //sΪ�մ�  s[0][j] = 0;
        for (int i = 0; i < s.size(); i++)
            dp[i][0] = 1;
        for (int j = 1; j < t.size(); j++)
            dp[0][j] = 0;

        //���ƹ�ʽ����� / �����
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                // �����Ǵ�s���� ����ɾ��s
                //��������dp[i][j]��dp[i-1][j-1]��ɾ��sβԪ�ص�dpֵ
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];  //����s��һλ��

            }
        }
        return dp[s.size()][t.size()];
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
    int res = obj->numDistinct(text1, text2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}