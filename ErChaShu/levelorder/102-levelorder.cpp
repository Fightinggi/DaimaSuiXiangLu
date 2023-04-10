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
//创建树
void insert(TreeNode*& root, int x) {
    if (root == NULL) { //空树，即查找失败，插入结点（递归边界）  
        root = new TreeNode(x); //创建新节点 
        return;
    }
    if (root->val > x) { //往左子树搜索 
        insert(root->left, x);  //root->lchild == null
    }
    else insert(root->right, x); //往右子树搜索
}
TreeNode* create(int data[], int n) {
    TreeNode* root = NULL;     //新建空根结点
    for (int i = 0; i < n; i++) {
        insert(root, data[i]); //将data[0]到data[n-1]插入二叉树
    }
    return root; //返回根节点
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
            num = que.size();//记录队列大小 知道每层的节点数，pop完放入第二层vec
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
//仿函数 打印一维数组
struct print001 {
    void operator()(int val) {
        cout << val << " ";
    }
};
void printvector(vector<int> res) {

    for_each(res.begin(), res.end(), print001());
    cout << endl;
}
//打印二维数组
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