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
//����һ���������ַ������� strs ���������� m �� n ��
//
//�����ҳ������� strs ������Ӽ��Ĵ�С�����Ӽ��� ��� �� m �� 0 �� n �� 1 ��
//
//��� x ������Ԫ��Ҳ�� y ��Ԫ�أ����� x �Ǽ��� y �� �Ӽ� ��
//
//ʾ�� 1��
//
//���룺strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
//
//�����4
//
//���ͣ������ 5 �� 0 �� 3 �� 1 ������Ӽ���{ "10","0001","1","0" } ����˴��� 4 �� 
//�����������⵫��С���Ӽ�����{ "0001","1" } ��{ "10","1","0" } ��{ "111001" } ���������⣬��Ϊ���� 4 �� 1 ������ n ��ֵ 3 ��
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs)  //������Ʒ
        {
            int zeroNums = 0; int oneNums = 0;
            for (char c : str)
            {
                if (c == '0') zeroNums++;
                else oneNums++;
            }
            //������ά���� �������
            for (int i = m; i >= zeroNums; i--)
            {
                for (int j = n; j >= oneNums; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNums][j - oneNums] + 1);
                    //�ַ�����zeroNum��oneNum�൱����Ʒ��������weight[i]��
                    //dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
                }
            }
        }
        return dp[m][n];
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
    vector<string> g = { "10", "0001", "111001", "1", "0" };
    TreeNode* root = NULL;
    int res = obj->findMaxForm(g, 5,3);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}