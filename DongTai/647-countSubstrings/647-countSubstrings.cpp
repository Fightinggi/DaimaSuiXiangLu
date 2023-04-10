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
//����һ���ַ�������������Ǽ�������ַ������ж��ٸ������Ӵ���
//
//���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ������ͬ���Ӵ���
//
//ʾ�� 1��
//
//���룺"abc"
//�����3
//���ͣ����������Ӵ� : "a", "b", "c"
class Solution {
public:
    //dp[i][j] ��ʾ����i��j������Ӵ��Ƿ�Ϊ�����Ӵ���
    //���ƹ�ʽ
    // 1. s[i]��s[j]�����ʱ��dp[i][j] = false;
    // 2, s[i]��s[j]���ʱ, i j ���С�ڵ���1  dp[i][j] = true;
    //                      i j ������1 dp[i][j] = dp[i+1][j-1]
    //��ʼ����Ϊfalse
    //����˳��  �µ��� ���� dp[i][j] = dp[i+1][j-1]
    //��� ���Ͻ�  j һ������ i
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