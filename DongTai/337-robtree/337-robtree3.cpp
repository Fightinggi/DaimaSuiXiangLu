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
//���ϴδ����һ���ֵ�֮���һȦ���ݺ�С͵�ַ�����һ���µĿ����Եĵ������������ֻ��һ����ڣ����ǳ�֮Ϊ�������� 
//���ˡ�����֮�⣬ÿ����������ֻ��һ��������������֮������һ�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����������һ�ö��������� 
//�������ֱ�������ķ�����ͬһ�����ϱ���٣����ݽ��Զ�������
//
//�����ڲ���������������£�С͵һ���ܹ���ȡ����߽�
class Solution {
public:

    vector<int> robtree(TreeNode* cur)
    {
        if (cur == NULL) return { 0, 0 };
        vector<int> left_dp = robtree(cur->left);
        vector<int> right_dp = robtree(cur->right);
        //��͵��ǰ�ڵ� ����͵�����ӽڵ�dp�����ֵ�ú͡�
        int val0 = max(left_dp[0], left_dp[1]) + max(right_dp[0], right_dp[1]);
        //͵��ǰ�ڵ� dp[1]�͵��ڵ�ǰ�ڵ��ֵ+�����ӽڵ�dp[0]��͵��ֵ��
        int val1 = cur->val + left_dp[0] + right_dp[0];;
        return { val0, val1 };
    }

    int rob(TreeNode* root) {

        vector<int> dp = robtree(root);
        return max(dp[0], dp[1]);  //����͵/��͵���ڵ�����ֵ
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