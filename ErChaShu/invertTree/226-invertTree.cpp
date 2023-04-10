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
        else cur->left = nullptr;

        //�Һ���  ͬ��
        if (i < n)
        {
            cur->right = new TreeNode(arr[i]);
            que.push(cur->right);
            i++;
        }
        else cur->right = nullptr;
    }
    return head; //����Ϊ���򷵻�ͷ�ڵ�
}

class Solution
{
public:
    //�ݹ�
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left,root->right);//������
        if (root->left) invertTree(root->left);
        if (root->right) invertTree(root->right);
        return root;
    }
    //���� ջ ǰ��
    TreeNode* invertTree2(TreeNode* root) {

        stack<TreeNode*> sta;
        if (root != NULL) sta.push(root);
        while (!sta.empty())
        {
            TreeNode* node = sta.top();  //��
            sta.pop();

            swap(node->left, node->right);//������ʵ��нڵ� ���ڵ�

            if (node->right) sta.push(node->right);   // ��
            if (node->left) sta.push(node->left);     // ��
        }
        return root;  
    }
    //�������
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
                swap(node->left, node->right);//������ʵ��нڵ� ���ڵ�
                if (node->left) que.push(node->left); //��
                if (node->right) que.push(node->right);//��
            }
        }
        return root;
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
    int n = 10;
    int nums[10] = { 5,3,8,2,4,1,6,7,9,0 };
    vector<int> arr(nums,nums+n);
    TreeNode* root = create(arr, arr.size());

    //��תǰ
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);


    //��ת��
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