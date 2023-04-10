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
//����һ��������������Ҳ������ظ����ֵ����飬�ҳ���Ϊ����Ŀ������������ϵĸ�����
//
//ʾ�� :
//
//nums = [1, 2, 3]
//target = 4
//���п��ܵ����Ϊ��(1, 1, 1, 1) (1, 1, 2) (1, 2, 1) (1, 3) (2, 1, 1) (2, 2) (3, 1)
//
//��ע�⣬˳��ͬ�����б�������ͬ����ϡ�
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        //��ȫ��������
        // ˳��ͬ�����б�������ͬ����ϡ�������
        //�������� �� dp[j] += dp[j-nums[i]];  �� �ȱ��������ٱ�����Ʒ
        //������� �� dp[j] += dp[j-nums[i]];  �� �ȱ�����Ʒ�ٱ�������
        //dp[j] = dp[j] + dp[j-nums[i]] ʢ��j������С�󱳰� ���������� return dp[target];
        //�������  ��ʼ��
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++)  //����
        {
            for (int i = 0; i < nums.size(); i++)  //��Ʒ
            {
                //C++������������������ӳ���int�����ݣ�������Ҫ��if�����dp[i] < INT_MAX - dp[i - num]��
                if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])
                    dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[target];
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
    int res = obj->combinationSum4(g,5);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}