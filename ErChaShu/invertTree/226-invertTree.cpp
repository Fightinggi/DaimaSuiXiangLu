#include<vector>
#include<queue>
#include<iostream>
#include<stack>
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
        root = new TreeNode(x); //创建新节点  截止条件  
        return;
    }
    if (root->val > x) { //往左子树搜索 
        insert(root->left, x);  //root->lchild == null
    }
    else insert(root->right, x); //往右子树搜索  root->val < x
}
TreeNode* create(vector<int> arr, int n) {
    TreeNode* root = NULL;     //新建空根结点
    for (int i = 0; i < n; i++) {
        insert(root, arr[i]); //将data[0]到data[n-1]插入二叉树
    }
    return root; //返回根节点
}
//层序遍历构建二叉树
TreeNode* creatBinTree(vector<int> arr, int n) {
       
    queue<TreeNode*> que;//构建队列 存放节点
    //如果数组为空，返回空树
    if (arr.empty()) return nullptr;

    //创建头节点为数组首元素 并进入队列
    TreeNode* head = new TreeNode(arr[0]);
    que.push(head);

    //创建当前队列 设置当前数组下标
    TreeNode* cur;
    int i = 1;

    //进入while循环 队列不为空 
    while (!que.empty())
    {
        // 每次循环 取出队首节点为当前节点  后续安排其左右子节点
        cur = que.front();  //第一次cur = head
        que.pop();

        // 左孩子  数组有元素 创建左孩子节点 并入队  更新数组下标
        if (i < n)
        {
            cur->left = new TreeNode(arr[i]);
            que.push(cur->left);
            i++;
        }
        else cur->left = nullptr;

        //右孩子  同理
        if (i < n)
        {
            cur->right = new TreeNode(arr[i]);
            que.push(cur->right);
            i++;
        }
        else cur->right = nullptr;
    }
    return head; //队列为空则返回头节点
}

class Solution
{
public:
    //递归
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left,root->right);//中左右
        if (root->left) invertTree(root->left);
        if (root->right) invertTree(root->right);
        return root;
    }
    //迭代 栈 前序
    TreeNode* invertTree2(TreeNode* root) {

        stack<TreeNode*> sta;
        if (root != NULL) sta.push(root);
        while (!sta.empty())
        {
            TreeNode* node = sta.top();  //中
            sta.pop();

            swap(node->left, node->right);//处理访问的中节点 根节点

            if (node->right) sta.push(node->right);   // 右
            if (node->left) sta.push(node->left);     // 左
        }
        return root;  
    }
    //层序遍历
    TreeNode* invertTree3(TreeNode* root) {

        queue<TreeNode*> que;
        int num;
        if (root != NULL) que.push(root);
        while (!que.empty())
        {
            num = que.size();
            for (int i = 0; i < num; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right);//处理访问的中节点 根节点
                if (node->left) que.push(node->left); //左
                if (node->right) que.push(node->right);//右
            }
        }
        return root;
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
//打印树  层序 
vector<vector<int>> levelOrder(TreeNode* root) {

    queue<TreeNode*> que;
    vector<vector<int>> res;
    int size;
    if (root != NULL) que.push(root);
    while (!que.empty())
    {
        size = que.size();//记录队列大小 知道每层的节点数，pop完放入第二层vec
        vector<int> vec;
        for (int i = 0; i < size; i++)
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
void test()
{
    int n = 10;
    int nums[10] = { 5,3,8,2,4,1,6,7,9,0 };
    vector<int> arr(nums,nums+n);
    TreeNode* root = create(arr, arr.size());

    //反转前
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);


    //反转后
    Solution* so = new Solution();
    TreeNode* res = so->invertTree2(root);
    vector<vector<int>> pri2 = levelOrder(res);
    printvector2(pri2);
}
int main()
{
    test();
    return 0;
}