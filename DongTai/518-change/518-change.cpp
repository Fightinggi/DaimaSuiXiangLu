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
//������ͬ����Ӳ�Һ�һ���ܽ�д��������������Դճ��ܽ���Ӳ�������������ÿһ������Ӳ�������޸���
//
//ʾ�� 1:
//
//����: amount = 5, coins = [1, 2, 5]
//��� : 4
//���� : �����ַ�ʽ���Դճ��ܽ�� :
//
//    5 = 5
//    5 = 2 + 2 + 1
//    5 = 2 + 1 + 1 + 1
//    5 = 1 + 1 + 1 + 1 + 1
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        //��ȫ�������⣺Ӳ�ҿ��ظ�ѡ��
        //�����������ܽ��amount
        //��Ʒ��������ͬ����Ӳ��conis
        //��Ʒ��ֵ��1���������
        //dp[amount]��ʾѡȡ��ͬ����Ӳ��conis��װ���ܽ��amount�������
        //���ƹ�ʽ��dp[j] = max(dp[j], dp[j-conis[i]]+1)   ; return dp[amount]
        //����˳��  ��Ʒ  ����  �������

        int bagSize = amount;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= bagSize; j++)  //�������
            {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[bagSize];
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
    vector<int> g = {1,2,5};
    TreeNode* root = NULL;
    int res = obj->change(5, g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}