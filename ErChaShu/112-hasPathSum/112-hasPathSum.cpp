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
//������
void insert(TreeNode*& root, int x) {
    if (root == NULL) { //������������ʧ�ܣ������㣨�ݹ�߽磩  
        root = new TreeNode(x); //�����½ڵ�  ��ֹ����  
        return;
    }
    if (root->val > x) { //������������ 
        insert(root->left, x);  //root->lchild == null
    }
    else insert(root->right, x); //������������  root->val < x
}
TreeNode* create(vector<int> arr, int n) {
    TreeNode* root = NULL;     //�½��ո����
    for (int i = 0; i < n; i++) {
        insert(root, arr[i]); //��data[0]��data[n-1]���������
    }
    return root; //���ظ��ڵ�
}
//�����������������
TreeNode* creatBinTree(vector<int> arr, int n) {

    queue<TreeNode*> que;//�������� ��Žڵ�
    //�������Ϊ�գ����ؿ���
    if (arr.empty()) return nullptr;

    //����ͷ�ڵ�Ϊ������Ԫ�� ���������
    TreeNode* head = new TreeNode(arr[0]);
    que.push(head);

    //������ǰ���� ���õ�ǰ�����±�
    TreeNode* cur;
    int i = 1;

    //����whileѭ�� ���в�Ϊ�� 
    while (!que.empty())
    {
        // ÿ��ѭ�� ȡ�����׽ڵ�Ϊ��ǰ�ڵ�  ���������������ӽڵ�
        cur = que.front();  //��һ��cur = head
        que.pop();

        // ����  ������Ԫ�� �������ӽڵ� �����  ���������±�
        if (i < n)
        {
            if (arr[i] == 0) cur->left = NULL;
            else {
                cur->left = new TreeNode(arr[i]);  //�������ӽڵ�
                que.push(cur->left);
            }
            i++;
        }
        else cur->left = NULL;

        //�Һ���  ͬ��
        if (i < n)
        {
            if (arr[i] == 0)
                cur->right = NULL;
            else {
                cur->right = new TreeNode(arr[i]);  //�����Һ��ӽڵ�
                que.push(cur->right);
            }
            i++;
        }
        else cur->right = NULL;
    }
    return head; //����Ϊ���򷵻�ͷ�ڵ�
}
class Solution {
public:

    //�ݹ�   û���нڵ�ô����߼� ǰ�к��򶼿�
    //���ȷ���Ƿ��з���ֵ
    //�����Ҫ�������ö������Ҳ��ô���ݹ鷵��ֵ���ݹ麯���Ͳ�Ҫ����ֵ��
    //�����Ҫ�������ö���������Ҫ����ݹ鷵��ֵ���ݹ麯������Ҫ����ֵ�� 
    //���Ҫ��������һ������������·������ô�ݹ�һ����Ҫ����ֵ����Ϊ��������������·���˾�Ҫ��ʱ���ء�

    //��ֹ���� ����Ҷ�ӽڵ� count==0 ����ture  ��������false
    //��Ҫȥ�ۼ�Ȼ���ж��Ƿ����Ŀ��ͣ���ô����Ƚ��鷳�������õݼ���
    //�ü�����count��ʼΪĿ��ͣ�Ȼ��ÿ�μ�ȥ����·���ڵ��ϵ���ֵ��

    bool traversal(TreeNode* node, int count)
    {
        //��ֹ����
        if (!node->left && !node->right && count == 0) return true;
        if (!node->left && !node->right) return false;


        if (node->left)
        {
            count -= node->left->val;
            if (traversal(node->left, count)) return true;
            count += node->left->val; //����
           
             //if (traversal(cur->left, count - cur->left->val)) return true; // ע�������л��ݵ��߼�
        }
        if (node->right)
        {
            count -= node->right->val;
            if (traversal(node->right, count)) return true;
            count += node->right->val; //����
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return traversal(root, targetSum - root->val);
    }
};
// ============/����=================
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if (root == NULL) return false;
        // ��ʱջ��Ҫ�ŵ���pair<�ڵ�ָ�룬·����ֵ>
        stack<pair<TreeNode*, int>> sta;
        sta.push(pair<TreeNode*, int>(root, root->val));
        while (!sta.empty())
        {
            //ջ ������
            pair<TreeNode*, int> cur = sta.top();
            sta.pop();

            //������Ԫ��
            // ����ýڵ���Ҷ�ӽڵ��ˣ�ͬʱ�ýڵ��·����ֵ����sum����ô�ͷ���true
            if (!cur.first->left && !cur.first->right && targetSum == cur.second) return true;

            //����ӽڵ��Ԫ�ؽ�ջ,ͬʱ����·����ֵ
            if (cur.first->right) sta.push(pair<TreeNode*, int>(cur.first->right, cur.second + cur.first->right->val));
            if (cur.first->left) sta.push(pair<TreeNode*, int>(cur.first->left, cur.second + cur.first->left->val));
        }
        return false;
    }
};
//===================#113. ·���ܺ�ii=======================
class Solution3 {
public:

    void traversal(TreeNode* cur, vector<int>& path, vector<vector<int>>& result,int targetSum) {

        path.push_back(cur->val); // �У���Ϊʲôд�������Ϊ���һ���ڵ�ҲҪ���뵽path�� 
        // ��ŵ���Ҷ�ӽڵ�  ��ֹ���� �����ӽڵ㶼Ϊ��
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
        //����ݹ��߼�
        if (cur->left) { // �� 
            traversal(cur->left, path, result, targetSum);
            path.pop_back(); // ����
        }
        if (cur->right) { // ��
            traversal(cur->right, path, result, targetSum);
            path.pop_back(); // ����
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
    // �ݹ麯������Ҫ����ֵ����Ϊ����Ҫ����������
    void traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) { // ������Ҷ�ӽڵ����ҵ��˺�Ϊsum��·��
            result.push_back(path);
            return;
        }

        if (!cur->left && !cur->right) return; // ����Ҷ�ӽڵ��û���ҵ����ʵıߣ�ֱ�ӷ���

        if (cur->left) { // �� ���սڵ㲻������
            path.push_back(cur->left->val);
            count -= cur->left->val;

            traversal(cur->left, count);    // �ݹ�
            count += cur->left->val;        // ����
            path.pop_back();                // ����
        }
        if (cur->right) { // �� ���սڵ㲻������
            path.push_back(cur->right->val);
            count -= cur->right->val;

            traversal(cur->right, count);   // �ݹ�
            count += cur->right->val;       // ����
            path.pop_back();                // ����
        }
        return;
    }

public:
    vector<vector<int>> pathsum(TreeNode* root, int sum) {
        result.clear();
        path.clear();
        if (root == NULL) return result;
        path.push_back(root->val); // �Ѹ��ڵ�Ž�·��
        traversal(root, sum - root->val);
        return result;
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

//============  ��ӡ��  ���� =============
//��ӡ��ά����
void printvector2(vector<vector<int>>& A) {
    for (vector<vector<int>>::iterator i = A.begin(); i != A.end(); i++) {
        for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//============  ������� ��Ŷ�ά���� =============
vector<vector<int>> levelOrder(TreeNode* root) {

    queue<TreeNode*> que;
    vector<vector<int>> res;
    int size;
    if (root != NULL) que.push(root);
    while (!que.empty())
    {
        size = que.size();//��¼���д�С ֪��ÿ��Ľڵ�����pop�����ڶ���vec
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


//�º��� ��ӡһά���� vector<string>
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

    //ǰ
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);

    //��
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