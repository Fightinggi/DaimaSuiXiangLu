#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//����һ�������������������Ľڵ��ϰ�װ����ͷ��
//
//�ڵ��ϵ�ÿ����Ӱͷ�����Լ����丸����������ֱ���Ӷ���
//
//�������������нڵ��������С����ͷ������
//
//ʾ�� 1��
//
//���룺[0, 0, null, 0, 0]
//�����1

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
private:

    // 0���޸���
    // 1��������ͷ
    // 2���и���
    int res;
    //�������������
    int traversal(TreeNode* cur)
    {
        //Ҷ�ӽڵ�Ϊ�յû�  �и��ǵ�״̬
        if (cur == nullptr) return 2;

        //������
        int left = traversal(cur->left);
        int right = traversal(cur->right);

        //���1  ���ҽڵ㶼�и���
        if (left == 2 && right == 2) return 0;

        //���2  ���ҽڵ�������һ������
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        //���3  ���ҽڵ�������һ����ͷ
        if (left == 1 || right == 1) return 2;

        return -1;// ��� return -1 �߼������ߵ����
    }
public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (traversal(root) == 0) //���ڵ��޸���Ҳû������ͷ�����ڸ��ڵ��һ������ͷ���root
            res++;
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
    vector<int> g = { 2,3,1,1,4 };
    TreeNode* root = NULL;
    int res = obj->minCameraCover(root);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}