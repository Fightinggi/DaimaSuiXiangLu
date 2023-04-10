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
//����һ������ n������ 1 ... n Ϊ�ڵ���ɵĶ����������ж����֣�
class Solution {
public:
    //dp[i] ��ʾ  1��iΪ�ڵ�Ķ����������ĸ���
    //���ƹ�ʽ dp[i] += dp[j-1] * dp[i-j]   j=1 j<=i j++
    //dp[i] += dp[��jΪͷ����������ڵ�����] * dp[��jΪͷ����������ڵ�����]
    //dp[0] = dp[1] = 1

    //���ɿɿ���  
    // n=3���ڵ� �� 1Ϊ�ڵ� �������ڵ�����1-1=0 ����������n-1=2  dp[0]*dp[2] = 1*2=2
    //              2Ϊ�ڵ� �������ڵ�����2-1=1 ����������n-2=1  dp[1]*dp[2] = 1*1=1
    //              3Ϊ�ڵ� �������ڵ�����3-1=2 ����������n-3=0  dp[2]*dp[0] = 2*1=2
    //��С��Ԫ�� dp[0] = dp[1] = 1    dp[2] = 2

    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
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
    vector<vector<int>> obstacleGrid = { {0, 0, 0},{0, 1, 0},{0, 0, 0} };
    int res = obj->numTrees(3);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}