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

    //递归   没有中节点得处理逻辑 前中后序都可
    //如何确定是否有返回值
    //如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。
    //如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。 
    //如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。

    //终止条件 到了叶子节点 count==0 返回ture  其他返回false
    //不要去累加然后判断是否等于目标和，那么代码比较麻烦，可以用递减，
    //让计数器count初始为目标和，然后每次减去遍历路径节点上的数值。

    bool traversal(TreeNode* node, int count)
    {
        //终止条件
        if (!node->left && !node->right && count == 0) return true;
        if (!node->left && !node->right) return false;


        if (node->left)
        {
            count -= node->left->val;
            if (traversal(node->left, count)) return true;
            count += node->left->val; //回溯
           
             //if (traversal(cur->left, count - cur->left->val)) return true; // 注意这里有回溯的逻辑
        }
        if (node->right)
        {
            count -= node->right->val;
            if (traversal(node->right, count)) return true;
            count += node->right->val; //回溯
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return traversal(root, targetSum - root->val);
    }
};
// ============/迭代=================
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if (root == NULL) return false;
        // 此时栈里要放的是pair<节点指针，路径数值>
        stack<pair<TreeNode*, int>> sta;
        sta.push(pair<TreeNode*, int>(root, root->val));
        while (!sta.empty())
        {
            //栈 顶弹出
            pair<TreeNode*, int> cur = sta.top();
            sta.pop();

            //处理弹出元素
            // 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
            if (!cur.first->left && !cur.first->right && targetSum == cur.second) return true;

            //添加子节点的元素进栈,同时更新路径数值
            if (cur.first->right) sta.push(pair<TreeNode*, int>(cur.first->right, cur.second + cur.first->right->val));
            if (cur.first->left) sta.push(pair<TreeNode*, int>(cur.first->left, cur.second + cur.first->left->val));
        }
        return false;
    }
};
//===================#113. 路径总和ii=======================
class Solution3 {
public:

    void traversal(TreeNode* cur, vector<int>& path, vector<vector<int>>& result,int targetSum) {

        path.push_back(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中 
        // 这才到了叶子节点  终止条件 左右子节点都为空
        if (cur->left == NULL && cur->right == NULL) {

            for (int i = 0; i < path.size(); i++) {
                targetSum -= path[i];
            }
            if (targetSum == 0)
            {
                result.push_back(path);
            }
            return;
        }
        //单层递归逻辑
        if (cur->left) { // 左 
            traversal(cur->left, path, result, targetSum);
            path.pop_back(); // 回溯
        }
        if (cur->right) { // 右
            traversal(cur->right, path, result, targetSum);
            path.pop_back(); // 回溯
        }
    }
    vector<vector<int>> hasPathSum(TreeNode* root,int targetSum) {

        vector<vector<int>> result;
        vector<int> path;
        if (root == NULL) return result;
        traversal(root, path, result, targetSum);
        return result;
    }
};
class solution4 {
private:
    vector<vector<int>> result;
    vector<int> path;
    // 递归函数不需要返回值，因为我们要遍历整个树
    void traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) { // 遇到了叶子节点且找到了和为sum的路径
            result.push_back(path);
            return;
        }

        if (!cur->left && !cur->right) return; // 遇到叶子节点而没有找到合适的边，直接返回

        if (cur->left) { // 左 （空节点不遍历）
            path.push_back(cur->left->val);
            count -= cur->left->val;

            traversal(cur->left, count);    // 递归
            count += cur->left->val;        // 回溯
            path.pop_back();                // 回溯
        }
        if (cur->right) { // 右 （空节点不遍历）
            path.push_back(cur->right->val);
            count -= cur->right->val;

            traversal(cur->right, count);   // 递归
            count += cur->right->val;       // 回溯
            path.pop_back();                // 回溯
        }
        return;
    }

public:
    vector<vector<int>> pathsum(TreeNode* root, int sum) {
        result.clear();
        path.clear();
        if (root == NULL) return result;
        path.push_back(root->val); // 把根节点放进路径
        traversal(root, sum - root->val);
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
    int n = 13;
    int nums[] = { 5,4,8,11,0,13,4,7,2,0,0,5,1 };
    vector<int> arr(nums, nums + n);
    TreeNode* root = creatBinTree(arr, arr.size());

    //前
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);

    //后
    Solution3* so = new Solution3();
    vector<vector<int>> res = so->hasPathSum(root,22);
    //print_vector_str(res);
    //cout << res << endl;
    //vector<vector<int>> pri2 = levelOrder(res);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}