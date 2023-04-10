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
	TreeNode* Node = new TreeNode; //申请一个node类型变量的地址空间
	Node->data = v; //结点权值为v
	Node->lchild = Node->rchild = NULL; //初始状态下无左右孩子
	return Node; //返回新节点的地址
}

void search(TreeNode* root, int x, int newdata) {
	if (root == NULL) return; //考虑为空节点的可能性
	if (root->data == x) {
		root->data = newdata; //找到数据域为x的结点，把它修改为newdata
	}
	search(root->lchild, x, newdata);//往左子树搜索
	search(root->rchild, x, newdata);//往右子树搜索
}

void insert(TreeNode*& root, int x) {//二叉搜索树
	if (root == NULL) { //空树，即查找失败，插入结点（递归边界）  
		root = newNode(x); //创建新节点 
		return;
	}
	if (root->data > x) { //往左子树搜索 
		insert(root->lchild, x);  //root->lchild == null
	}
	else insert(root->rchild, x); //往右子树搜索
}

TreeNode* create(int data[], int n) {
	TreeNode* root = NULL;     //新建空根结点
	for (int i = 0; i < n; i++) {
		insert(root, data[i]); //将data[0]到data[n-1]插入二叉树
	}
	return root; //返回根节点
}

void preorder(TreeNode* root) { //先序遍历 中左右
	if (root == NULL) return; //到达空树，即递归边界
	cout << root->data << endl;; //访问根节点数据域
	preorder(root->lchild); //访问左子树
	preorder(root->rchild); //访问右子树
}

void inorder(TreeNode* root) { //中序遍历
	if (root == NULL) return; //到达空树，即递归边界
	inorder(root->lchild); //访问左子树
	cout << root->data << endl;; //访问根节点数据域
	inorder(root->rchild); //访问右子树
}
void postorder(TreeNode* root) { //后序遍历
	if (root == NULL) return; //到达空树，即递归边界
	postorder(root->lchild); //访问左子树
	postorder(root->rchild); //访问右子树
	cout << root->data << endl;; //访问根节点数据域
}

void LayerOrder(TreeNode* root) { //层序遍历
	queue<TreeNode*> q; //队列里面存的是地址 记得导入头文件<quene>
	q.push(root);  //将根节点入队
	while (!q.empty())  //退出条件为队列为空
	{
		TreeNode* now = q.front(); //取出队首元素
		cout << now->data << endl;
		q.pop();        //弹出队首元素
		if (now->lchild != NULL) q.push(now->lchild);//左子树非空则压入队列
		if (now->rchild != NULL) q.push(now->rchild);//右子树非空则压入队列
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
//============  打印树  层序 =============
//打印二维数组
void printvector2(TreeNode* root) {
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
	// 双指针
	// 递归  中序  
	static  TreeNode* pre;
	static bool isValidBST(TreeNode* root) {

		if (root == NULL) return true;

		bool left = isValidBST(root->lchild);//左

		//如果当前值小于前一个，说明左下大于其根节点  是不对的
		if (pre != NULL && root->data <= pre->data) return false;
		pre = root;// 记录前一个节点  这里用的中序（左中右）  这里的意思是从左下往上   pre代表左下  root代表中

		bool right = isValidBST(root->rchild);//右
		return left && right;
	}
};
TreeNode* Solution3::pre = NULL;
int main() {
	int n = 10;
	int nums[10] = { 5,3,8,2,4,1,6,7,9,0 };
	TreeNode* root = create(nums, 10);//构建二叉搜索树
	//cout << "搜索树？" << Solution3().isValidBST(root) << endl;  //Solution3().  匿名对象
	cout << "搜索树？" << Solution3::isValidBST(root) << endl;  //成员函数声明为static
	//search(root, 7, 11); //查找替换
	//preorder(root);//前序遍历
	//inorder(root);    //中序遍历
	//postorder(root);  //后序遍历
	printvector2(root);  //层序遍历
	system("pause");
	return 0;
}