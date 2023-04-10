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
//����һ���������� prices �����ĵ� i ��Ԫ�� prices[i] ��һ֧�����Ĺ�Ʊ�ڵ� i ��ļ۸�
//
//���һ���㷨�����������ܻ�ȡ�������������������� k �ʽ��ס�
//
//ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
//
//ʾ�� 1�� ���룺k = 2, prices = [2, 4, 1] �����2 ���ͣ��ڵ� 1 ��(��Ʊ�۸� = 2) ��ʱ�����룬�ڵ� 2 ��(��Ʊ�۸� = 4) ��ʱ��������
//��ʽ������ܻ������ = 4 - 2 = 2��
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int len = prices.size();
        if (len == 0) return 0;
        //��ʼ��
        vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k; j += 2) {
            dp[0][j] = -prices[0];
        }
        //����
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j < 2 * k - 1; j += 2)
            {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);  //����
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);  //������
            }
        }
        return dp[len - 1][2 * k];
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
    int res = obj->maxProfit(2,g2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}