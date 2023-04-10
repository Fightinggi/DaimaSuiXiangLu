#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//������������¥�ݡ���Ҫ n ������ܵ���¥����
//
//ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
//
//ע�⣺���� n ��һ����������
//���룺 3
//����� 3
//���ͣ� �����ַ�����������¥����
//1 �� + 1 �� + 1 ��
//1 �� + 2 ��
//2 �� + 1 ��
class Solution {
public:

    //dp[i]��ʾ�����i�������dp[i]�ַ���
    //dp[i] = dp[i-1] + dp[i-2] ���ͣ�dp[i-1]����1�׻���dp[i-2]����2�� �����Դﵽi��
    //��ʼ��dp[1] = 1, dp[2] = 2
    //�Ӻ���ǰ

    int climbStairs(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
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
    vector<int> g = { 2,3,1,1,4 };
    TreeNode* root = NULL;
    int res = obj->climbStairs(3);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}