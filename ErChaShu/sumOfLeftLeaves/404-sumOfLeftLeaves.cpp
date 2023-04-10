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
                cur->left = new TreeNode(arr[i]);
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
                cur->right = new TreeNode(arr[i]);
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

    //�ݹ�
    int sumOfLeftLeaves(TreeNode* root) {

        if (root == NULL) return 0;
        if (root->right == NULL && root->left == NULL) return 0;
        //������

        int LeftLeaves = sumOfLeftLeaves(root->left);//��
        //ȡ������ ��Ҷ�ӽڵ��ֵ ���жϺ������ǲ�֪�� �Ƿ����� Ҷ�ӽڵ� Ҳ��������Ҷ�ӽڵ�
        if (root->left && !root->left->left && !root->left->right)
        {
            LeftLeaves = root->left->val;
        }

        int rightLeaves = sumOfLeftLeaves(root->right);//��

        int sum = LeftLeaves + rightLeaves; //��
        return sum;
    }
};
// ============/����=================
class Solution2 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //ǰ��  ջ 
        if (root == NULL) return 0;
        stack<TreeNode*> sta;
        sta.push(root);
        int sum = 0;
        while (!sta.empty())
        {
            TreeNode* cur = sta.top();
            sta.pop();

            if (cur->left != NULL && !cur->left->left && !cur->left->right)
            {
                sum += cur->left->val;  //���
            }

            if (cur->right) sta.push(cur->right);
            if (cur->left) sta.push(cur->left);
        }
        return sum;
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
    int n = 7;
    int nums[] = { 3,9,20,0,0,15,7 };
    vector<int> arr(nums, nums + n);
    TreeNode* root = creatBinTree(arr, arr.size());

    //ǰ
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);

    //��
    Solution2* so = new Solution2();
    int res = so->sumOfLeftLeaves(root);
    //print_vector_str(res);
    cout << res << endl;
    //vector<vector<int>> pri2 = levelOrder(res);
    //printvector2(pri2);
}
int main()
{
    test();
    return 0;
}