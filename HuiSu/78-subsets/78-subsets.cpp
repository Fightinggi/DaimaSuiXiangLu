#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//输入：nums = [1, 2, 3]
//输出： [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
//那么组合问题和分割问题都是收集树的叶子节点，而子集问题是找树的所有节点！
class Solution {
public:

    //存放结果
    vector<int> path;
    vector<vector<int>> res;


    //回溯函数
    void back(vector<int>& nums, int start_index)
    {
        //处理结果
        res.push_back(path);

        //终止条件
        if (start_index >= nums.size())
        {
            return;
        }
        //单层搜索
        for (int i = start_index; i < nums.size(); i++) //{1,2}和{2,1}属于一个集合
        {
            path.push_back(nums[i]);
            back(nums, i + 1);//{1,2}和{2,1}属于一个集合
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        res.clear();
        path.clear();
        back(nums, 0);
        return res;

    }
};

//仿函数 打印一维数组 vector<string>
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
//打印二维数组
void printvector2(vector<vector<int>>& A) {
    cout << "[";

    for (vector<vector<int>>::iterator i = A.begin(); i != A.end(); i++) {
        cout << "[";
        
        for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
            cout << *j << ",";
        }

        cout << "],";
        //cout << endl;
    }
    cout << "]";
    /*cout << endl;*/
}
void test()
{
    Solution* s = new Solution();
    vector<int> in = { 1,2,3 };
    vector<vector<int>> res = s->subsets(in);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}