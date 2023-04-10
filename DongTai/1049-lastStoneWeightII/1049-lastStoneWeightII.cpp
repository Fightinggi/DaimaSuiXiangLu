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
//��һ��ʯͷ��ÿ��ʯͷ������������������
//
//ÿһ�غϣ�����ѡ����������ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊ x �� y���� x <= y����ô����Ŀ��ܽ�����£�
//
//��� x == y����ô����ʯͷ���ᱻ��ȫ���飻
//
//��� x != y����ô����Ϊ x ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y - x��
//
//������ֻ��ʣ��һ��ʯͷ�����ش�ʯͷ��С�Ŀ������������û��ʯͷʣ�£��ͷ��� 0��
//
//ʾ����
//
//���룺[2, 7, 4, 1, 8, 1]
//�����1
//���ͣ�
//
//��� 2 �� 4���õ� 2����������ת��Ϊ[2, 7, 1, 8, 1]��
//��� 7 �� 8���õ� 1����������ת��Ϊ[2, 1, 1, 1]��
//��� 2 �� 1���õ� 1����������ת��Ϊ[1, 1, 1]��
//��� 1 �� 1���õ� 0����������ת��Ϊ[1]�����������ֵ��
class Solution {
public:

    int lastStoneWeightII(vector<int>& stones) {
        int sums = 0;
        for (int i = 0; i < stones.size(); i++)
            sums += stones[i];

        //01��������
        //��������sums/2
        //��Ʒ����=��Ʒ��ֵnums[i]
        vector<int> weight(stones);
        vector<int> value(stones);
        int bagWeight = sums / 2;

        //��ʼ��
        vector<int> dp(bagWeight + 1, 0);
        for (int i = 0; i < weight.size(); i++)
        {
            for (int j = bagWeight; j >= weight[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }

        return sums - 2 * dp[bagWeight];

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
    vector<int> g = { 2,7,4,1,8,1 };
    TreeNode* root = NULL;
    int res = obj->lastStoneWeightII(g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}