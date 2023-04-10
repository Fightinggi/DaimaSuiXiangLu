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
//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
//
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ����
//
//���ܹ��ж�������ͬ��·����
//ʾ�� 2��
//
//���룺m = 2, n = 3
//�����3
//���ͣ� �����Ͻǿ�ʼ���ܹ��� 3 ��·�����Ե������½ǡ�
//
//����->����->����
//����->����->����
//����->����->����
class Solution {
public:
    int uniquePaths(int m, int n) {

        //dp[i][j]��ʾ��(0,0)��(i,j)�ж�����·��
        //���ƹ�ʽ��dp[i][j] = dp[i-1][j] + dp[i][j-1]  ���»��������ƶ�һ��
        //��ʼ����һ�е��� �� ��һ�е��� ֻ��һ��·�� ����dp[0][j] + dp[i][0]��ʼ��Ϊ1
        //����˳��i,j�ֱ��ǰ���

        //�����ά����  ����dp(i,j)���������״̬
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int raw = 0; raw < m; raw++) dp[raw][0] = 1;
        for (int rol = 0; rol < n; rol++) dp[0][rol] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
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
    int res = obj->uniquePaths(4,3);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}