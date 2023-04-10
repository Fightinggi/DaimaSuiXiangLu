#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <unordered_set>
using namespace std;
//给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
//
//示例 :
//
//输入: [4, 6, 7, 7]
//输出 : [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7, 7], [4, 7, 7]]

//回溯算法 ；嵌套n个for循环
class Solution {
public:

    //存放结果
    vector<int> path;
    vector<vector<int>> res;

    //回溯函数
    void back(vector<int>& nums, int start_index)
    {
        //处理结果
        if (path.size() > 1) res.push_back(path);

        //树枝递归逻辑  uset支队本层进行去重操作
        unordered_set<int> uset;  //每进行一次递归，就是每下一层，重新设置uset，

        //树层 本层集合中的元素，节点孩子的数量==集合的大小
        for (int i = start_index; i < nums.size(); i++)
        {
            //树层去重逻辑 set  
            //nums[i]取得下一个数 小于 集合中最后的数（上一层取的数） 则跳出本次循环
            //去重：集合中有相同的数
            if (!path.empty() && nums[i] < path.back()
                || uset.find(nums[i]) != uset.end())
                continue;
            //递归 回溯
            uset.insert(nums[i]);// // 记录这个元素在本层用过了，本层后面不能再用了,不需要回溯了
            path.push_back(nums[i]);
            back(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

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
    vector<int> arr = {4,6,7,7 };
    vector<vector<int>> res = s->findSubsequences(arr);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}
