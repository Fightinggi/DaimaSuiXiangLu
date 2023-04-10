#include<vector>
#include<stack>
#include <queue>
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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {//�������  ������  ���ʺʹ�����ͬͬһ�ڵ�  ���ڵ� �нڵ�
            TreeNode* node = st.top();                       // ��
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);           // �ң��սڵ㲻��ջ��
            if (node->left) st.push(node->left);             // �󣨿սڵ㲻��ջ��
        }
        return result;
    }
    vector<int> inorderTraversal(TreeNode * root) {
        
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur!=NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;//��
            }
            else
            {
                cur = st.top();//��
                st.pop();
                result.push_back(cur->val);

                cur = cur->right;//��
            }
        }
        return result;
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())  //������(ǰ��)  ������  ��ת  �����У�����
        {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);  
            if (node->left) st.push(node->left); // �����ǰ������������һ����ջ˳�� ���սڵ㲻��ջ��
            if (node->right) st.push(node->right); // �սڵ㲻��ջ
        }
        reverse(result.begin(), result.end());
        return result;
    }
    //�������
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            // ����һ��Ҫʹ�ù̶���Сsize����Ҫʹ��que.size()����Ϊque.size�ǲ��ϱ仯��
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};