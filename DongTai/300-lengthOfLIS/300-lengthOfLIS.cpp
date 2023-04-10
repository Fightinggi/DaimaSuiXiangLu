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
//����һ���������� nums ���ҵ�������ϸ���������еĳ��ȡ�
//
//���������������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳�����磬[3, 6, 2, 7] ������[0, 3, 1, 6, 2, 2, 7] �������С�
//
//ʾ�� 1��
//
//���룺nums = [10, 9, 2, 5, 3, 7, 101, 18]
//�����4
//���ͣ��������������[2, 3, 7, 101]����˳���Ϊ 4 ��
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        //1.����dp[i]���� ��ʾ i ֮ǰ���� i ����nums[i]��β����ݹ������г���
        //2.���ƹ�ʽ��if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1)
        //dp[j] ��ʾ��0��i-1 ��ݹ������г���
        //��ʼ�� dp[i]=1;
        int len = nums.size();
        if (len <= 1) return nums.size();
        int res = 0;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; i++)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > res) res = dp[i];
        }
        return res;
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
    vector<int> g2 = { 7,1,5,3,6,4 };
    string s = "leetcode";
    int res = obj->lengthOfLIS(g2);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}