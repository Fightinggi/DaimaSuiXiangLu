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
//����һ��ֻ�����������ķǿ����顣�Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�
//
//ע�� : ÿ�������е�Ԫ�ز��ᳬ�� 100 ����Ĵ�С���ᳬ�� 200
//
//ʾ�� 1 :
//
//    ���� : [1, 5, 11, 5]
//    ��� : true
//    ���� : ������Էָ��[1, 5, 5] ��[11].
class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sums = 0;
        for (int i = 0; i < nums.size(); i++)
            sums += nums[i];
        if (sums % 2 != 0) return false;
        //01��������
        //��������sums/2
        //��Ʒ����=��Ʒ��ֵnums[i]
        vector<int> weight(nums);
        vector<int> value(nums);
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

        return sums / 2 == dp[bagWeight];

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
    vector<int> g = { 1,5,11,5 };
    TreeNode* root = NULL;
    int res = obj->canPartition(g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}