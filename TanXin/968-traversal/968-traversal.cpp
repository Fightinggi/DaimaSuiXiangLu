#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//给定一个二叉树，我们在树的节点上安装摄像头。
//
//节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
//
//计算监控树的所有节点所需的最小摄像头数量。
//
//示例 1：
//
//输入：[0, 0, null, 0, 0]
//输出：1

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
private:

    // 0、无覆盖
    // 1、有摄像头
    // 2、有覆盖
    int res;
    //二叉树后序遍历
    int traversal(TreeNode* cur)
    {
        //叶子节点为空得话  有覆盖得状态
        if (cur == nullptr) return 2;

        //左右中
        int left = traversal(cur->left);
        int right = traversal(cur->right);

        //情况1  左右节点都有覆盖
        if (left == 2 && right == 2) return 0;

        //情况2  左右节点至少有一个覆盖
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        //情况3  左右节点至少有一摄像头
        if (left == 1 || right == 1) return 2;

        return -1;// 这个 return -1 逻辑不会走到这里。
    }
public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (traversal(root) == 0) //根节点无覆盖也没有摄像头，就在根节点放一个摄像头监控root
            res++;
        return res;

    }
};

//仿函数 打印一维数组 vector<string>
template<typename T>
struct print002 {
    void operator()(T val) {
        cout << val << " ";
    }
};
template<typename T>
void print_vector_str(vector<T> res)
{
    for_each(res.begin(), res.end(), print002<T>());
    cout << endl;
}
//打印二维数组
template<typename T>
void PrintVecofVec2(vector<vector<T>>& res) {
    for (auto& rowV : res) {
        for (auto& el : rowV) {
            cout << el << " ";
        }
        cout << "; ";
    }
    cout << endl;
}
void test()
{
    Solution* obj = new Solution();
    vector<int> g = { 2,3,1,1,4 };
    TreeNode* root = NULL;
    int res = obj->minCameraCover(root);
    cout << res << endl;
    //print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}