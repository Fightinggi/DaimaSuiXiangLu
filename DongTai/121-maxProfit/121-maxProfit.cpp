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
//����һ������ prices �����ĵ� i ��Ԫ�� prices[i] ��ʾһ֧������Ʊ�� i ��ļ۸�
//
//��ֻ��ѡ�� ĳһ�� ������ֻ��Ʊ����ѡ���� δ����ĳһ����ͬ������ �����ù�Ʊ�����һ���㷨�����������ܻ�ȡ���������
//
//��������Դ���ʽ����л�ȡ�������������㲻�ܻ�ȡ�κ����󣬷��� 0 ��
//
//ʾ�� 1��
//���룺[7, 1, 5, 3, 6, 4]
//�����5
//���ͣ��ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������
//������� = 6 - 1 = 5 ��ע���������� 7 - 1 = 6, ��Ϊ�����۸���Ҫ��������۸�ͬʱ���㲻��������ǰ������Ʊ��
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] ��ʾ��i����й�Ʊ��������ֽ�
        // dp[i][1] ��ʾ��i�첻���й�Ʊ��������ֽ�
        int len = prices.size();
        if (len == 0) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        // return max(dp[len][0], dp[len][1]);
        return dp[len - 1][1];  //�����й�Ʊ״̬���ý�Ǯһ���ȳ��й�Ʊ״̬�õ��Ķ࣡
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
    int res = obj->maxProfit(g2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}