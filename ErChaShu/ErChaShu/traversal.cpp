#include <iostream>
#include <queue>
#include <queue>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode* lchild;
	TreeNode* rchild;
	TreeNode() :data(0), lchild(nullptr), rchild(nullptr) {}
	TreeNode(int x) :data(x), lchild(nullptr), rchild(nullptr) {}
	TreeNode(char x) :data(x), lchild(nullptr), rchild(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :data(x), lchild(left), rchild(right) {}
};

TreeNode* newNode(int v) {
	TreeNode* Node = new TreeNode; //����һ��node���ͱ����ĵ�ַ�ռ�
	Node->data = v; //���ȨֵΪv
	Node->lchild = Node->rchild = NULL; //��ʼ״̬�������Һ���
	return Node; //�����½ڵ�ĵ�ַ
}

void search(TreeNode* root, int x, int newdata) {
	if (root == NULL) return; //����Ϊ�սڵ�Ŀ�����
	if (root->data == x) {
		root->data = newdata; //�ҵ�������Ϊx�Ľ�㣬�����޸�Ϊnewdata
	}
	search(root->lchild, x, newdata);//������������
	search(root->rchild, x, newdata);//������������
}

void insert(TreeNode*& root, int x) {//����������
	if (root == NULL) { //������������ʧ�ܣ������㣨�ݹ�߽磩  
		root = newNode(x); //�����½ڵ� 
		return;
	}
	if (root->data > x) { //������������ 
		insert(root->lchild, x);  //root->lchild == null
	}
	else insert(root->rchild, x); //������������
}

TreeNode* create(int data[], int n) {
	TreeNode* root = NULL;     //�½��ո����
	for (int i = 0; i < n; i++) {
		insert(root, data[i]); //��data[0]��data[n-1]���������
	}
	return root; //���ظ��ڵ�
}

void preorder(TreeNode* root) { //������� ������
	if (root == NULL) return; //������������ݹ�߽�
	cout << root->data << endl;; //���ʸ��ڵ�������
	preorder(root->lchild); //����������
	preorder(root->rchild); //����������
}

void inorder(TreeNode* root) { //�������
	if (root == NULL) return; //������������ݹ�߽�
	inorder(root->lchild); //����������
	cout << root->data << endl;; //���ʸ��ڵ�������
	inorder(root->rchild); //����������
}
void postorder(TreeNode* root) { //�������
	if (root == NULL) return; //������������ݹ�߽�
	postorder(root->lchild); //����������
	postorder(root->rchild); //����������
	cout << root->data << endl;; //���ʸ��ڵ�������
}

void LayerOrder(TreeNode* root) { //�������
	queue<TreeNode*> q; //�����������ǵ�ַ �ǵõ���ͷ�ļ�<quene>
	q.push(root);  //�����ڵ����
	while (!q.empty())  //�˳�����Ϊ����Ϊ��
	{
		TreeNode* now = q.front(); //ȡ������Ԫ��
		cout << now->data << endl;
		q.pop();        //��������Ԫ��
		if (now->lchild != NULL) q.push(now->lchild);//�������ǿ���ѹ�����
		if (now->rchild != NULL) q.push(now->rchild);//�������ǿ���ѹ�����
	}
}

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
void printvector2(TreeNode* root) {
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
			vec.push_back(node->data);
			if (node->lchild) que.push(node->lchild);
			if (node->rchild) que.push(node->rchild);
		}
		res.push_back(vec);
	}
	
	for (vector<vector<int>>::iterator i = res.begin(); i != res.end(); i++) {
		for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
			cout << *j << " ";
		}
		cout << endl;
	}
	cout << endl;
}
class Solution3 {
public:
	// ˫ָ��
	// �ݹ�  ����  
	static  TreeNode* pre;
	static bool isValidBST(TreeNode* root) {

		if (root == NULL) return true;

		bool left = isValidBST(root->lchild);//��

		//�����ǰֵС��ǰһ����˵�����´�������ڵ�  �ǲ��Ե�
		if (pre != NULL && root->data <= pre->data) return false;
		pre = root;// ��¼ǰһ���ڵ�  �����õ����������ң�  �������˼�Ǵ���������   pre��������  root������

		bool right = isValidBST(root->rchild);//��
		return left && right;
	}
};
TreeNode* Solution3::pre = NULL;
int main() {
	int n = 10;
	int nums[10] = { 5,3,8,2,4,1,6,7,9,0 };
	TreeNode* root = create(nums, 10);//��������������
	//cout << "��������" << Solution3().isValidBST(root) << endl;  //Solution3().  ��������
	cout << "��������" << Solution3::isValidBST(root) << endl;  //��Ա��������Ϊstatic
	//search(root, 7, 11); //�����滻
	//preorder(root);//ǰ�����
	//inorder(root);    //�������
	//postorder(root);  //�������
	printvector2(root);  //�������
	system("pause");
	return 0;
}