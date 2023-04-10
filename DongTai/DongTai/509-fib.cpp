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
//쳲���������ͨ���� F(n) ��ʾ���γɵ����г�Ϊ 쳲��������� ���������� 0 �� 1 ��ʼ��
// �����ÿһ�����ֶ���ǰ���������ֵĺ͡�Ҳ���ǣ� F(0) = 0��F(1) = 1 F(n) = F(n - 1) + F(n - 2)������ n > 1 ����n ������� F(n) ��
//
//ʾ�� 1��
//
//���룺2
//�����1
//���ͣ�F(2) = F(1) + F(0) = 1 + 0 = 1
class Solution {
public:
    int fib(int n) {

        if (n <= 1) return n;
        //dp����dp[i]��ʾ��i��쳲�����ֵ
        //���ƹ�ʽF(n) = F(n - 1) + F(n - 2)
        //��ʼ��F(0) = 0��F(1) = 1
        //����˳��F(n)����F(n - 1) F(n - 2)  ��ǰ����

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
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
    int res = obj->fib(3);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}