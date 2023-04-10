#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
//
//示例 1：
//
//输入：nums = [1, 1, 2]
//输出： [[1, 1, 2], [1, 2, 1], [2, 1, 1]]
class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void back(vector<int>& nums, vector<bool>& used)
    {
        if (nums.size() == path.size())
        {
            res.push_back(path);
            return;
        }
        //去重逻辑
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            if (used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            back(nums, used);
            used[i] = false;
            path.pop_back();
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
    vector<int> arr = { 1,1,1,2,2 };
    vector<vector<int>> res = s->permuteUnique(arr);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}
