#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ��
// ����������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
//
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�
//
//ʾ�� 1��
//���룺[1, 2, 3, 1]
//�����4
//���ͣ�͵�� 1 �ŷ���(��� = 1) ��Ȼ��͵�� 3 �ŷ���(��� = 3)��   ͵�Ե�����߽�� = 1 + 3 = 4 ��
class Solution {
public:
    // dp[i]�������±�i������i�����ڵķ��ݣ�������͵�ԵĽ��Ϊdp[i]��
    // ���ƹ�ʽ��
    // ͵��i���䣬��ôdp[i] = dp[i - 2] + nums[i] 
    // ��͵��i���䣬��ôdp[i] = dp[i - 1]
    // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    // ��ʼ�� dp[0] һ���� nums[0]��dp[1] = max(nums[0], nums[1]);
    // �������

    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);  //+nums[i]��ʾ͵��i�䷿��
        }
        return dp[nums.size() - 1];
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
    vector<string> g = { "leet", "code" };
    vector<int> g2 = { 1,2,3,1 };
    string s = "leetcode";
    int res = obj->rob(g2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}