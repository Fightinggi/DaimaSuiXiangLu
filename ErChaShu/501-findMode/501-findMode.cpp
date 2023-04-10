#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <unordered_map>
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
    //0. ���������������
    //1. ǰ�����������searchBST��mapͳ��valƵ��
    //2. ����ص�����cmp������value��С
    //3. �ҵ����г���Ƶ����ߵ�Ԫ�� for

    // ��������

    void searchBST(TreeNode* cur, unordered_map<int, int>& map)
    {
        if (cur == NULL) return;
        map[cur->val]++;
        searchBST(cur->left, map);
        searchBST(cur->right, map);
        return;
    }
    bool static cmp(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;// key:Ԫ�أ�value:����Ƶ��
        vector<int> res;
        if (root == NULL) return res;

        searchBST(root, map);
        // �е�ͬѧ���ܿ�����ֱ�Ӷ�map�е�value���򣬻�����������C++�����ʹ��std::map����std::multimap���Զ�key���򣬵����ܶ�value����
        // ����Ҫ��mapת�����鼴vector���ٽ������򣬵�Ȼvector����ŵ�Ҳ��pair<int, int>���͵����ݣ���һ��intΪԪ�أ��ڶ���intΪ����Ƶ�ʡ�
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);//���� value Ƶ��
        res.push_back(vec[0].first);//��һ�������ڵ��val
        for (int i = 1; i < vec.size(); i++)//Ѱ����ͬvalue�������Ľڵ�val������ŵ�res
        {
            if (vec[i].second == vec[0].second) res.push_back(vec[i].first);
            else break;
        }
        return res;

    }
};
class Solution2 {
public:

    //0. �������������
    //1. ���������
    //2. ˫ָ��pre cur
    //3. �Ƚ�pre->val==cur->val
    //4. ����count++ ����¼maxCount�������������
    
    // ����һ��

    int maxCount = 0;
    int count = 0;
    TreeNode* pre = NULL;
    vector<int> res;
    void searchBST(TreeNode* cur)
    {
        if (cur == NULL) return;
        //������
        searchBST(cur->left);

        //����ڵ�
        if (pre == NULL) count = 1;//Ҷ�ӽڵ� Ҳ�ǵ�һ���ڵ�  // Ƶ��Ϊ1
        else if (pre->val == cur->val)  count++;
        else count = 1;  // ��ǰһ���ڵ���ֵ��ͬ
        pre = cur;//������һ���ڵ�

        // �����������  ���maxCount��ʱ�������������Ƶ���أ� ��Ҫ����������ж�
        // ��������ֵ�Ͱ������Ƶ�ʴ�����������������Ҫclear������ͳ��
        if (count == maxCount) res.push_back(cur->val);

        // �Ƚ�maxCount
        if (count > maxCount)  // ��������������ֵƵ�ʣ�����ͳ���������ĸ�ֵ������ŵ�res��
        {
            maxCount = count; // �������Ƶ��
            res.clear();  // �ܹؼ���һ������Ҫ�������result��֮ǰresult���Ԫ�ض�ʧЧ��
            res.push_back(cur->val);
        }
        searchBST(cur->right);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        //=====��ʼ��=======
        maxCount = 0;
        count = 0;
        res.clear();
        TreeNode* pre = NULL;
        //===== ִ��=====
        searchBST(root);
        return res;

    }
};

class Solution3 {
public:

    //============���� �е㲻һ�� ������============


    vector<int> findMode(TreeNode* root) {
        //=====��ʼ��=======
        int maxCount = 0;
        int count = 0;
        vector<int> res;
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        stack<TreeNode*> sta;

        while (cur != NULL || !sta.empty())
        {
            if (cur != NULL)
            {
                sta.push(cur);
                cur = cur->left;//��
            }
            else
            {
                //��
                cur = sta.top();
                sta.pop();

                if (pre == NULL) count = 1;
                else if (pre->val == cur->val)  count++;
                else count = 1;
                if (count == maxCount) res.push_back(cur->val);
                if (count > maxCount)
                {
                    maxCount = count;
                    res.clear();
                    res.push_back(cur->val);
                }
                pre = cur;

                cur = cur->right;  //��
            }

        }
        return res;
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
//�º��� ��ӡһά���� vector<int>

void print_int(int val) {
    cout << val <<" ";
}

void print_vector_int(vector<int> res)
{
    //����1
    for (auto array : res) {
        std::cout << array << " ";
    }
    //����2
    std::for_each(res.begin(), res.end(), [](const auto& i) {std::cout << i << " "; });
    for_each(res.begin(), res.end(), print_int);

    //����3
    for (auto it = res.begin(); it != res.end(); ++it) {
        std::cout << *it << " ";
    }

    cout << endl;
}
void test()
{
    int n = 4;
    int nums[] = { 1,0,2,2 };
    vector<int> arr(nums, nums + n);

    TreeNode* root = creatBinTree(arr, arr.size());  //��������arr�����򹹽�������

    //ǰ
    vector<vector<int>> pri1 = levelOrder(root);
    printvector2(pri1);


    //��
    Solution3* so = new Solution3();

    vector<int> arr1 = { 1,3,2,5,0,0,0 };
    vector<int> arr2 = { 2,1,3,0,4,0,7 };
    TreeNode* root1 = creatBinTree(arr1, arr1.size());  //��������arr�����򹹽�������
    TreeNode* root2 = creatBinTree(arr2, arr2.size());  //��������arr�����򹹽�������
    vector<int> res = so->findMode(root);  //��������
    print_vector_int(res);
    //cout << res << endl;
    //vector<vector<int>> pri2 = levelOrder(res);  //������� �� ��ŵ���ά����
    //printvector2(pri2);                         //��ӡ��ά����
    //print_LayerOrder(res);
}
int main()
{
    test();
    return 0;
}