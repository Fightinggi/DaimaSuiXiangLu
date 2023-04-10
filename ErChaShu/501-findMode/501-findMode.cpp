#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <unordered_map>
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
    //0. 不是搜索树的情况
    //1. 前序遍历二叉树searchBST，map统计val频率
    //2. 排序回调函数cmp，根据value大小
    //3. 找到所有出现频率最高的元素 for

    // 遍历两次

    void searchBST(TreeNode* cur, unordered_map<int, int>& map)
    {
        if (cur == NULL) return;
        map[cur->val]++;
        searchBST(cur->left, map);
        searchBST(cur->right, map);
        return;
    }
    bool static cmp(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;// key:元素，value:出现频率
        vector<int> res;
        if (root == NULL) return res;

        searchBST(root, map);
        // 有的同学可能可以想直接对map中的value排序，还真做不到，C++中如果使用std::map或者std::multimap可以对key排序，但不能对value排序。
        // 所以要把map转化数组即vector，再进行排序，当然vector里面放的也是pair<int, int>类型的数据，第一个int为元素，第二个int为出现频率。
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);//排序 value 频率
        res.push_back(vec[0].first);//第一个众数节点的val
        for (int i = 1; i < vec.size(); i++)//寻找相同value的众数的节点val，并存放到res
        {
            if (vec[i].second == vec[0].second) res.push_back(vec[i].first);
            else break;
        }
        return res;

    }
};
class Solution2 {
public:

    //0. 是搜索树的情况
    //1. 中序遍历。
    //2. 双指针pre cur
    //3. 比较pre->val==cur->val
    //4. 计数count++ ，记录maxCount，存放众数集合
    
    // 遍历一次

    int maxCount = 0;
    int count = 0;
    TreeNode* pre = NULL;
    vector<int> res;
    void searchBST(TreeNode* cur)
    {
        if (cur == NULL) return;
        //左中右
        searchBST(cur->left);

        //处理节点
        if (pre == NULL) count = 1;//叶子节点 也是第一个节点  // 频率为1
        else if (pre->val == cur->val)  count++;
        else count = 1;  // 与前一个节点数值不同
        pre = cur;//更新上一个节点

        // 存放众数集合  这个maxCount此时还不是真正最大频率呢， 需要左接下来的判断
        // 如果是最大值就按照这个频率存放众数，如果不是则要clear，重新统计
        if (count == maxCount) res.push_back(cur->val);

        // 比较maxCount
        if (count > maxCount)  // 如果计数大于最大值频率，重新统计众数是哪个值，并存放到res中
        {
            maxCount = count; // 更新最大频率
            res.clear();  // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
            res.push_back(cur->val);
        }
        searchBST(cur->right);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        //=====初始化=======
        maxCount = 0;
        count = 0;
        res.clear();
        TreeNode* pre = NULL;
        //===== 执行=====
        searchBST(root);
        return res;

    }
};

class Solution3 {
public:

    //============中序 有点不一样 迭代法============


    vector<int> findMode(TreeNode* root) {
        //=====初始化=======
        int maxCount = 0;
        int count = 0;
        vector<int> res;
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        stack<TreeNode*> sta;

        while (cur != NULL || !sta.empty())
        {
            if (cur != NULL)
            {
                sta.push(cur);
                cur = cur->left;//左
            }
            else
            {
                //中
                cur = sta.top();
                sta.pop();

                if (pre == NULL) count = 1;
                else if (pre->val == cur->val)  count++;
                else count = 1;
                if (count == maxCount) res.push_back(cur->val);
                if (count > maxCount)
                {
                    maxCount = count;
                    res.clear();
                    res.push_back(cur->val);
                }
                pre = cur;

                cur = cur->right;  //右
            }

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
//仿函数 打印一维数组 vector<int>

void print_int(int val) {
    cout << val <<" ";
}

void print_vector_int(vector<int> res)
{
    //方法1
    for (auto array : res) {
        std::cout << array << " ";
    }
    //方法2
    std::for_each(res.begin(), res.end(), [](const auto& i) {std::cout << i << " "; });
    for_each(res.begin(), res.end(), print_int);

    //方法3
    for (auto it = res.begin(); it != res.end(); ++it) {
        std::cout << *it << " ";
    }

    cout << endl;
}
void test()
{
    int n = 4;
    int nums[] = { 1,0,2,2 };
    vector<int> arr(nums, nums + n);

    TreeNode* root = creatBinTree(arr, arr.size());  //按照数组arr，层序构建二叉树

    //前
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);


    //后
    Solution3* so = new Solution3();

    vector<int> arr1 = { 1,3,2,5,0,0,0 };
    vector<int> arr2 = { 2,1,3,0,4,0,7 };
    TreeNode* root1 = creatBinTree(arr1, arr1.size());  //按照数组arr，层序构建二叉树
    TreeNode* root2 = creatBinTree(arr2, arr2.size());  //按照数组arr，层序构建二叉树
    vector<int> res = so->findMode(root);  //最大二叉树
    print_vector_int(res);
    //cout << res << endl;
    //vector<vector<int>> pri2 = levelOrder(res);  //层序遍历 并 存放到二维数组
    //printvector2(pri2);                         //打印二维数组
    //print_LayerOrder(res);
}
int main()
{
    test();
    return 0;
}