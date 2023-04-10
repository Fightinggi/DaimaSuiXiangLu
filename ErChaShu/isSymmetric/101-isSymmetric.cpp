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
public:
    //=================�ݹ�======================
    bool compare(TreeNode* left, TreeNode* right) {
        // �����ų��սڵ�����
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        // �ų��˿սڵ㣬���ų���ֵ����ͬ�����
        else if (left->val != right->val) return false;

        // ȷ������ݹ���߼�
        // ��ʱ���ǣ����ҽڵ㶼��Ϊ�գ�����ֵ��ͬ�����  
        // ��ʱ�����ݹ飬����һ����ж�
        bool outside = compare(left->left, right->right);   // ���������� ����������
        bool inside = compare(left->right, right->left);    // ���������ҡ� ����������
        bool isSame = outside && inside;                    // ���������С� ���������� ���߼�����
        return isSame;

    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }

    //=================����======================
    bool isSymmetric2(TreeNode* root) {
        
        if (root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        //�ж������� �Ƿ��໥��ת
        while (!que.empty())
        {
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            if (!leftNode && !rightNode) {  // ��ڵ�Ϊ�ա��ҽڵ�Ϊ�գ���ʱ˵���ǶԳƵ�
                continue;
            }
            // ����һ���ڵ㲻Ϊ�գ����߶���Ϊ�յ���ֵ����ͬ������false
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }
            // outside �Ƚ�
            que.push(leftNode->left);
            que.push(rightNode->right);

            // inside �Ƚ�
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
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
    int n = 7;
    int nums[7] = { 1,2,2,3,4,4,3 };
    vector<int> arr(nums, nums + n);
    TreeNode* root = creatBinTree(arr, arr.size());

    //ǰ
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);


    //��
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