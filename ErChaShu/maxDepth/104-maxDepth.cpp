#include<vector>
#include<queue>
#include<iostream>
#include<stack>
using namespace std;
#define Kong 0
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
            if (arr[i] == Kong) cur->left = NULL;
            else {
                cur->left = new TreeNode(arr[i]);
                que.push(cur->left);
            }
            i++;
        }
        else cur->left = NULL;

        //右孩子  同理
        if (i < n)
        {
            if (arr[i] == Kong)
                cur->right = NULL;
            else {
                cur->right = new TreeNode(arr[i]);
                que.push(cur->right);
            }
            i++;
        }
        else cur->right = NULL;
    }
    return head; //队列为空则返回头节点
}

class Solution {
public:
    //====================递归================
    int getdepth(TreeNode* node)
    {
        if (node == nullptr) return 0;  //空节点 高度为 0
        int leftdepth = getdepth(node->left);//左
        int rightdepth = getdepth(node->right);//右
        int depth = 1 + max(leftdepth, rightdepth);//中
        return depth;
    }
    // 高度：该节点到叶子节点 的最长简单路径边的条数后者节点数
    // 深度：根节点到该节点   的最长简单路径边的条数或者节点数
    // 求高度用后序遍历，求深度用前序
    // 根节点高度 就是 二叉树最大深度 
    // 这里求 根节点root 高度用后序左右中
    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
    //题外：
    // 最小深度是从根节点到最近叶子节点的最短路径上的节点数量
    // 什么是叶子节点，左右孩子都为空的节点才是叶子节点！

    //====================迭代================
    //层序遍历
    int maxdepth2(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++; // 记录深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};
// ============求节点深度-前序遍历=================
class Solution2 {
public:
    int result;
    void getDepth(TreeNode* node, int depth) {

        result = depth > result ? depth : result; // 中
        if (node->left == NULL && node->right == NULL) return;
        
        if (node->left) { // 左
            getDepth(node->left, depth + 1);

            /*
            depth++;
            getDepth(node->left, depth);
            depth--;  回溯
            */
        }
        if (node->right) { // 右
            getDepth(node->right, depth + 1);
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        result = 0;
        if (root == 0) return result;
        getDepth(root, 1);
        return result;
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
    cout << endl;
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
    int n = 7;
    int nums[7] = { 3,9,20,Kong,Kong,15,7 };
    vector<int> arr(nums, nums + n);
    TreeNode* root = creatBinTree(arr, arr.size());

    //前
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);

    //后
    Solution* so = new Solution();
    int res = so->maxdepth2(root);
    cout << res << endl;
    //vector<vector<int>> pri2 = levelOrder(res);
    //printvector2(pri2);
}
int main()
{
    test();
    return 0;
}