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
//�����ÿ���±���Ϊһ�����ݣ��� i �����ݶ�Ӧ��һ���Ǹ�������������ֵ cost[i]���±�� 0 ��ʼ����
//
//ÿ��������һ�������㶼Ҫ���Ѷ�Ӧ������ֵ��һ��֧������Ӧ������ֵ����Ϳ���ѡ��������һ�����ݻ������������ݡ�
//
//�����ҳ��ﵽ¥�㶥������ͻ��ѡ��ڿ�ʼʱ�������ѡ����±�Ϊ 0 �� 1 ��Ԫ����Ϊ��ʼ���ݡ�
//
//ʾ�� 1��
//
//���룺cost = [10, 15, 20]
//�����15
//���ͣ���ͻ����Ǵ� cost[1] ��ʼ��Ȼ�����������ɵ����ݶ���һ������ 15 ��
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        //dp[i]��ʾ�����i��¥����Ҫ���ѵ���С����
        //���ƹ�ʽ��dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
        //��ʼ�� dp[0] = 0; dp[1] = 0,���±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�����������
        //����˳�� ��ǰ����
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
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
    vector<int> g = { 2,3,1,1,4 };
    TreeNode* root = NULL;
    int res = obj->minCostClimbingStairs(g);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}