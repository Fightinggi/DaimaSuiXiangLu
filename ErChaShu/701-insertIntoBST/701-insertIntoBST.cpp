#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
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
            if (arr[i] == 0) cur->left = NULL;
            else {
                cur->left = new TreeNode(arr[i]);  //创建左孩子节点
                que.push(cur->left);
            }
            i++;
        }
        else cur->left = NULL;

        //右孩子  同理
        if (i < n)
        {
            if (arr[i] == 0)
                cur->right = NULL;
            else {
                cur->right = new TreeNode(arr[i]);  //创建右孩子节点
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root==NULL)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if(root->val > val)
            root->left = insertIntoBST(root->left,val);
        if(root->val < val)
            root->right = insertIntoBST(root->right,val);

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
void print_LayerOrder(TreeNode* root) { //层序遍历
    queue<TreeNode*> que;
    int size;
    if (root != NULL) que.push(root);
    while (!que.empty())
    {
        size = que.size();//记录队列大小 知道每层的节点数，pop完放入第二层vec
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = que.front();
            que.pop();
            cout << node->val << " ";

            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }
}

//============  打印树  层序 =============
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
//============  层序遍历 存放二维数组 =============
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


//仿函数 打印一维数组 vector<string>
struct print002 {
    void operator()(string val) {
        cout << val << " ";
    }
};
void print_vector_str(vector<string> res)
{
    for_each(res.begin(), res.end(), print002());
    cout << endl;
}
void test()
{
    int n = 5;
    int nums[] = { 4,2,7,1,3 };
    vector<int> arr(nums, nums + n);

    TreeNode* root = creatBinTree(arr, arr.size());  //按照数组arr，层序构建二叉树

    //前
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);


    //后
    Solution* so = new Solution();

    vector<int> arr1 = { 1,3,2,5,0,0,0 };
    vector<int> arr2 = { 2,1,3,0,4,0,7 };
    TreeNode* root1 = creatBinTree(arr1, arr1.size());  //按照数组arr，层序构建二叉树
    TreeNode* root2 = creatBinTree(arr2, arr2.size());  //按照数组arr，层序构建二叉树
    TreeNode* res = so->insertIntoBST(root, 5);  //二叉树
    //print_vector_str(res);
    //cout << res << endl;
    vector<vector<int>> pri2 = levelOrder(res);  //层序遍历 并 存放到二维数组
    printvector2(pri2);                         //打印二维数组
    //print_LayerOrder(res);
}
int main()
{
    test();
    return 0;
}