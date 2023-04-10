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
//������ͬ����Ӳ�� coins ��һ���ܽ�� amount����дһ��������������Դճ��ܽ����������ٵ�Ӳ�Ҹ��������û���κ�һ��Ӳ�����������ܽ����� - 1��
//
//�������Ϊÿ��Ӳ�ҵ����������޵ġ�
//
//ʾ�� 1��
//
//���룺coins = [1, 2, 5], amount = 11
//�����3
//���ͣ�11 = 5 + 5 + 1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        //��ȫ��������  ������ǰ�������
        //���������/�������������Ӽ��ô�С������Ʒ��ֵΪ1ʱ������Ϊj�ñ���װ����Ʒ������
        // dp[j] = min(dp[j], dp[j-coins[i]] + 1)   dp[j]�������ܶ�Ϊj����Ǯ�ҵ����ٸ���Ϊdp[j]
        //�ο�һ����  ���Ӽ���С  value[i] = 1
        //����˳�� ����Ʒ �ٱ���
        //��ʼ����  �����max  ��ʼ�� ��Ϊ��Сֵ0
        //          ����Сmin  ��ʼ�� ��Ϊ���ֵINT_MAX
        vector<int> dp(amount + 1, INT_MAX);  //��������
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) // ��Ʒ
        {
            for (int j = coins[i]; j <= amount; j++)  //����
            {
                if (dp[j - coins[i]] != INT_MAX) // ���dp[j - coins[i]]�ǳ�ʼֵ������
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
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
    int res = obj->combinationSum4(5, g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}