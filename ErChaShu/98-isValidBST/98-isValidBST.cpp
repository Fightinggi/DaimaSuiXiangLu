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
 class Solution1 {
 public:
     vector<int> vec;
     //�������������  ������������ ������� �����ǵ�����
     void inorder(TreeNode* root)
     {
         if(root==nullptr) return;
         inorder(root->left);
         vec.push_back(root->val);
         inorder(root->right);
     }
     bool isValidBST(TreeNode* root) {
         inorder(root);
         for(int i=1;i<vec.size();i++)
         {
             if(vec[i] <= vec[i-1])  return false;
         }
         return true;
     }
 };

 class Solution2 {
 public:
     long long maxVal = LONG_MIN; // ��Ϊ��̨������������int��Сֵ   
     //==============�ݹ�  ����===============
     bool isValidBST(TreeNode* root) {

         if(root==NULL) return true;

         bool left = isValidBST(root->left);//��

         //�����ǰֵС��maxVal��˵�����´�������ڵ�  �ǲ��Ե�
         if(root->val > maxVal) maxVal = root->val;
         else return false;

         bool right = isValidBST(root->right);//��
         return left && right;
     }
 };

class Solution3 {
public:
    // ˫ָ��
    // �ݹ�  ����  
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {

        if (root == NULL) return true;

        bool left = isValidBST(root->left);//��

        //�����ǰֵС��ǰһ����˵�����´�������ڵ�  �ǲ��Ե�
        if (pre != NULL && root->val <= pre->val) return false;
        pre = root;// ��¼ǰһ���ڵ�  �����õ����������ң�  �������˼�Ǵ���������   pre��������  root������

        bool right = isValidBST(root->right);//��
        return left && right;
    }
};
class Solution4 {
public:
    //������
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL; // ��¼ǰһ���ڵ�
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;                // ��
            }
            else {
                cur = st.top();                 // ��
                st.pop();

                if (pre != NULL && cur->val <= pre->val)
                    return false;
                pre = cur; //����ǰһ�����ʵĽ��

                cur = cur->right;               // ��
            }
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
    int n = 7;
    int nums[] = { 5,1,4,0,0,3,6 };
    vector<int> arr(nums, nums + n);

    TreeNode* root = creatBinTree(arr, arr.size());  //��������arr�����򹹽�������

    //ǰ
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);


    //��
    Solution1* so = new Solution1();

    vector<int> arr1 = { 1,3,2,5,0,0,0 };
    vector<int> arr2 = { 2,1,3,0,4,0,7 };
    TreeNode* root1 = creatBinTree(arr1, arr1.size());  //��������arr�����򹹽�������
    TreeNode* root2 = creatBinTree(arr2, arr2.size());  //��������arr�����򹹽�������
    bool res = so->isValidBST(root);  //��������
    //print_vector_str(res);
    cout << res << endl;
    //vector<vector<int>> pri2 = levelOrder(res);  //������� �� ��ŵ���ά����
    //printvector2(pri2);                         //��ӡ��ά����
    //print_LayerOrder(res);
}
int main()
{
    test();
    return 0;
}