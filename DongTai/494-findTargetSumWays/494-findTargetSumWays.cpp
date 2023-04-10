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
//����һ���Ǹ��������飬a1, a2, ..., an, ��һ��Ŀ������S������������������ + �� - �����������е�����һ���������㶼���Դ� + �� - ��ѡ��һ�����������ǰ�档
//
//���ؿ���ʹ���������ΪĿ���� S ��������ӷ��ŵķ�������
//
//ʾ����
//
//���룺nums : [1, 1, 1, 1, 1] , S : 3
//�����5
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sums = 0;
        for (int i = 0; i < nums.size(); i++)
            sums += nums[i];
        if (abs(target) > sums) return 0; // ��ʱû�з���
        if ((target + sums) % 2 == 1) return 0; // ��ʱû�з���
        //01��������
        //��������(sums+target)/2
        //��Ʒ����=��Ʒ��ֵnums[i]

        int bagSize = (sums + target) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = bagSize; j >= nums[i]; j--)
            {
                dp[j] = dp[j] + dp[j - nums[i]];
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
    vector<int> g = { 1,1,1,1,1 };
    TreeNode* root = NULL;
    int res = obj->findTargetSumWays(g,3);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}