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
//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
//
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
//
//���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
//���룺obstacleGrid = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
//�����2 ���ͣ�
//3x3 ��������м���һ���ϰ��
//�����Ͻǵ����½�һ���� 2 ����ͬ��·����
//����->����->����->����
//����->����->����->����
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        //dp[i][j] ����ʾ�ӣ�0 ��0����������(i, j) ��dp[i][j]����ͬ��·����
        //dp[i][j] = dp[i - 1][j] + dp[i][j - 1]��(i, j)��������ϰ��Ļ�Ӧ�þͱ��ֳ�ʼ״̬����ʼ״̬Ϊ0��
        //��ʼ�� �ϰ�֮���dp[i][0]Ӧ�û��ǳ�ʼֵ0
        //����˳��i,j�ֱ��ǰ������ϰ���ִ�е��ƹ�ʽ
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));  // vector<int> s(��С, ֵ)  ����ʼ״̬Ϊ0��

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) //����������յ�������ϰ���ֱ�ӷ���0
            return 0;
        for (int raw = 0; raw < m && obstacleGrid[raw][0] == 0; raw++) {
            dp[raw][0] = 1;
        }
        for (int rol = 0; rol < n && obstacleGrid[0][rol] == 0; rol++) {
            dp[0][rol] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                //�����ϰ� ������dp[i][j]���� ��Ϊ��ʼ״̬0
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
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
    vector<vector<int>> obstacleGrid = { {0, 0, 0},{0, 1, 0},{0, 0, 0} };
    int res = obj->uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}