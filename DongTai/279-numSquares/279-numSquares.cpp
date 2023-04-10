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
//���������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��ʹ�����ǵĺ͵��� n��
//����Ҫ����ɺ͵���ȫƽ�����ĸ������١�
//
//����һ������ n �����غ�Ϊ n ����ȫƽ������ �������� ��
//
//ʾ�� 1��
//
//���룺n = 12
//�����3
//���ͣ�12 = 4 + 4 + 4
class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n + 1, INT_MAX);  //��������
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) // ��Ʒ
        {
            for (int j = i * i; j <= n; j++)  //����
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
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
    vector<int> g = { 1,2,5 };
    TreeNode* root = NULL;
    int res = obj->numSquares(5);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}