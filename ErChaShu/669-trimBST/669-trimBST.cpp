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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //����������������  ��С����   ��<��<��
        if (root == nullptr) return nullptr;
        //���root��valС��low����root���Һ��ӷ��ص���һ��....��������root������,,,root��ߵ���������Ҫ��
        if (root->val < low) return trimBST(root->right, low, high);
        //���root��val����low����root�����ӷ��ص���һ��....��������root������,,,root��ߵ���������Ҫ��
        if (root->val > high) return trimBST(root->left, low, high);
        //��һ��Ĳ���
        root->left = trimBST(root->left, low, high);  //�ѷ��ϵ�����������
        root->right = trimBST(root->right, low, high);

        return root;
    }
};

//��Ϊ�����������������ԣ�����Ҫʹ��ջģ��ݹ�Ĺ��̡�
// ��root�ƶ���[L, R] ��Χ�ڣ�ע��������ұ�����
// ��֦������
// ��֦������
 class Solution2 {
 public:
     TreeNode* trimBST(TreeNode* root, int L, int R) {
         if (!root) return nullptr;

         // ����ͷ��㣬��root�ƶ���[L, R] ��Χ�ڣ�ע��������ұ�
         while (root != nullptr && (root->val < L || root->val > R)) {
             if (root->val < L) root = root->right; // С��L������
             else root = root->left; // ����R������
         }
         TreeNode *cur = root;
         // ��ʱroot�Ѿ���[L, R] ��Χ�ڣ���������Ԫ��С��L�����
         while (cur != nullptr) {
             while (cur->left && cur->left->val < L) {
                 cur->left = cur->left->right;
             }
             cur = cur->left;
         }
         cur = root;

         // ��ʱroot�Ѿ���[L, R] ��Χ�ڣ������Һ��Ӵ���R�����
         while (cur != nullptr) {
             while (cur->right && cur->right->val > R) {
                 cur->right = cur->right->left;
             }
             cur = cur->right;
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
void print_LayerOrder(TreeNode* root) { //�������
    queue<TreeNode*> que;
    int size;
    if (root != NULL) que.push(root);
    while (!que.empty())
    {
        size = que.size();//��¼���д�С ֪��ÿ��Ľڵ�����pop�����ڶ���vec
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
    int n = 8;
    int nums[] = { 4,1,5,0,3,0,0,2 };
    vector<int> arr(nums, nums + n);

    TreeNode* root = creatBinTree(arr, arr.size());  //��������arr�����򹹽�������

    //ǰ
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);


    //��
    Solution* so = new Solution();

    vector<int> arr1 = { 1,3,2,5,0,0,0 };
    vector<int> arr2 = { 2,1,3,0,4,0,7 };
    TreeNode* root1 = creatBinTree(arr1, arr1.size());  //��������arr�����򹹽�������
    TreeNode* root2 = creatBinTree(arr2, arr2.size());  //��������arr�����򹹽�������
    TreeNode* res = so->trimBST(root, 2,4);  //�޼�������
    //print_vector_str(res);
    //cout << res << endl;
    vector<vector<int>> pri2 = levelOrder(res);  //������� �� ��ŵ���ά����
    printvector2(pri2);                         //��ӡ��ά����
    //print_LayerOrder(res);
}
int main()
{
    test();
    return 0;
}