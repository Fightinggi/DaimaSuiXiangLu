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
        else cur->left = NULL;

        //右孩子  同理
        if (i < n)
        {
            cur->right = new TreeNode(arr[i]);
            que.push(cur->right);
            i++;
        }
        else cur->right = NULL;
    }
    return head; //队列为空则返回头节点
}

class Solution {
public:
    //=================递归======================
    bool compare(TreeNode* left, TreeNode* right) {
        // 首先排除空节点的情况
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val) return false;

        // 确定单层递归的逻辑
        // 此时就是：左右节点都不为空，且数值相同的情况  
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right);   // 左子树：左、 右子树：右
        bool inside = compare(left->right, right->left);    // 左子树：右、 右子树：左
        bool isSame = outside && inside;                    // 左子树：中、 右子树：中 （逻辑处理）
        return isSame;

    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }

    //=================迭代======================
    bool isSymmetric2(TreeNode* root) {
        
        if (root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        //判断左右树 是否相互翻转
        while (!que.empty())
        {
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            if (!leftNode && !rightNode) {  // 左节点为空、右节点为空，此时说明是对称的
                continue;
            }
            // 左右一个节点不为空，或者都不为空但数值不相同，返回false
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }
            // outside 比较
            que.push(leftNode->left);
            que.push(rightNode->right);

            // inside 比较
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
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
    int n = 7;
    int nums[7] = { 1,2,2,3,4,4,3 };
    vector<int> arr(nums, nums + n);
    TreeNode* root = creatBinTree(arr, arr.size());

    //前
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);


    //后
    Solution* so = new Solution();
    bool res = so->isSymmetric2(root);
    cout << res << endl;
    //vector<vector<int>> pri2 = levelOrder(res);
    //printvector2(pri2);
}
int main()
{
    test();
    return 0;
}