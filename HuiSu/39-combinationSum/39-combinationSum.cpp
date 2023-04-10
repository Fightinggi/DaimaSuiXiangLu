#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的数字可以无限制重复被选取。
//回溯算法 ；嵌套n个for循环
class Solution {
public:

    vector<int> path;
    vector<vector<int>> res;
    void back(vector<int>& candidates, int sum, int target, int index)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        // 如果 sum + candidates[i] > target 就终止遍历
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)  //同一集合
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            back(candidates, sum, target, i);//不用i+1了，表示可以重复读取当前的数
            sum -= candidates[i];
            path.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        if (candidates.size() == 0)
            return res;

        sort(candidates.begin(), candidates.end());
        back(candidates, 0, target, 0);
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
    vector<int> arr = { 2,3,6,7 };
    vector<vector<int>> res = s->combinationSum(arr, 7);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}