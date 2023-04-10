#include<vector>
#include<queue>
#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};
//������
void insert(TreeNode*& root, int x) {
    if (root == NULL) { //������������ʧ�ܣ������㣨�ݹ�߽磩  
        root = new TreeNode(x); //�����½ڵ� 
        return;
    }
    if (root->val > x) { //������������ 
        insert(root->left, x);  //root->lchild == null
    }
    else insert(root->right, x); //������������
}
TreeNode* create(int data[], int n) {
    TreeNode* root = NULL;     //�½��ո����
    for (int i = 0; i < n; i++) {
        insert(root, data[i]); //��data[0]��data[n-1]���������
    }
    return root; //���ظ��ڵ�
}

class Solution
{
public:
	vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> que;
        vector<vector<int>> res;
        int num;
        if (root != NULL) que.push(root);
        while (!que.empty())
        {
            num = que.size();//��¼���д�С ֪��ÿ��Ľڵ�����pop�����ڶ���vec
            vector<int> vec;
            for (int i = 0; i < num; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
	}
};
//�º��� ��ӡһά����
struct print001 {
    void operator()(int val) {
        cout << val << " ";
    }
};
void printvector(vector<int> res) {

    for_each(res.begin(), res.end(), print001());
    cout << endl;
}
//��ӡ��ά����
void printvector2(vector<vector<int>>& A) {
    for (vector<vector<int>>::iterator i = A.begin(); i != A.end(); i++) {
        for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
}
void test()
{
    int n = 10;
    int nums[10] = { 5,3,8,2,4,1,6,7,9,0 };
    TreeNode* root = create(nums, 10);

    Solution *so = new Solution();

    vector<vector<int>> res = so->levelOrder(root);
    printvector2(res);


}
int main()
{
    test();
    return 0;
}