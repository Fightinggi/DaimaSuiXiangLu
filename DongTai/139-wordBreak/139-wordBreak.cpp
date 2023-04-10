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
//����һ���ǿ��ַ��� s ��һ�������ǿյ��ʵ��б� wordDict���ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ�
//
//˵����
//
//���ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
//
//����Լ����ֵ���û���ظ��ĵ��ʡ�
//
//ʾ�� 1��
//
//���� : s = "leetcode", wordDict = ["leet", "code"]
//��� : true
//���� : ���� true ��Ϊ "leetcode" ���Ա���ֳ� "leet code"��
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        //��ȫ��������
        //��������  �ַ���j����
        //��Ʒ����  �ֵ��еĵ��ʴ�С
        //������  �����˳����Ҫ��
        // dp[i] : �ַ�������Ϊi�Ļ���dp[i]Ϊtrue����ʾ���Բ��Ϊһ���������ֵ��г��ֵĵ��ʡ�

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int j = 1; j <= s.size(); j++)  //����
        {
            for (int i = 0; i < j; i++)  //��Ʒ
            {
                string word = s.substr(i, j - i); //substr(��ʼλ�ã���ȡ�ĸ���)  ��Ʒ
                if (dp[i] == true && wordSet.find(word) != wordSet.end())
                    dp[j] = true;
            }
        }
        return dp[s.size()];
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