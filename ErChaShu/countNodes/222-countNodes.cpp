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
            cur->left = new TreeNode(arr[i]);
            que.push(cur->left);
            i++;
        }
        else cur->left = NULL;

        //�Һ���  ͬ��
        if (i < n)
        {
            cur->right = new TreeNode(arr[i]);
            que.push(cur->right);
            i++;
        }
        else cur->right = NULL;
    }
    return head; //����Ϊ���򷵻�ͷ�ڵ�
}

class Solution {
private:
    //===========�ݹ�==============
    int getNodesNum(TreeNode* cur) {
        if (cur == NULL) return 0;
        int leftNum = getNodesNum(cur->left);      // ��
        int rightNum = getNodesNum(cur->right);    // ��
        int treeNum = leftNum + rightNum + 1;      // ��
        return treeNum;
    }
public:
    int countNodes(TreeNode* root) {
        return getNodesNum(root);
    }
    //==============����========����===========
    int countNodes2(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                result++;   // ��¼�ڵ�����
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
    //============��ȫ������������===================
    int countNodes3(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftDepth = 0, rightDepth = 0; // �����ʼΪ0����Ŀ�ĵģ�Ϊ��������ָ������
        while (left) {  // �����������
            left = left->left;
            leftDepth++;
        }
        while (right) { // �����������
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1; // ע��(2<<1) �൱��2^2������leftDepth��ʼΪ0
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
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
    cout << endl;
}
//��ӡ��  ���� 
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
void test()
{
    int n = 3;
    int nums[3] = { 1,2,3 };
    vector<int> arr(nums, nums + n);
    TreeNode* root = creatBinTree(arr, arr.size());

    //ǰ
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);

    //��
    Solution* so = new Solution();
    int res = so->countNodes(root);
    cout << res << endl;
    //vector<vector<int>> pri2 = levelOrder(res);
    //printvector2(pri2);
}
int main()
{
    test();
    return 0;
}