#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//
//给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//
//示例 :
//
//输入: [1, 2, 3]
//输出 : [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
class Solution {
public:

    //存放结果
    vector<int> path;
    vector<vector<int>> res;

    //回溯函数
    void back(vector<int>& nums, vector<bool>& used)
    {
        //处理结果  所有叶子节点 
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        //单层搜索
        for (int i = 0; i < nums.size(); i++)
        {
            //或者if (used[i] == true) continue; // path里已经收录的元素，直接跳过
            //题目条件
            if (used[i] == false)
            {
                //递归
                used[i] = true;
                path.push_back(nums[i]);
                back(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        back(nums, used);
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
    for (vector<vector<int>>::iterator i = A.begin(); i != A.end(); i++) {
        for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void test()
{
    Solution* s = new Solution();
    vector<int> arr = {1,2,3 };
    vector<vector<int>> res = s->permute(arr);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}
