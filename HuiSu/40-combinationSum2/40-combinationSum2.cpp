#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用 一次 。
//
//注意：解集不能包含重复的组合

//回溯算法 ；嵌套n个for循环
class Solution {
public:

    vector<int> path;
    vector<vector<int>> res;
    void back(vector<int>& candidates, int sum, int target, int index, vector<bool>& used)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(path);
            return;
        }

        //单层搜索
        // 如果 sum + candidates[i] > target 就终止遍历   
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)  //同一集合
        {
            //去重  
            //used[i-1] == True 说明同一树枝candidates[i - 1]使用过
            //used[i-1] == False 说明到下一层树枝了，被回溯成false了。
            //要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            {
                continue;//candidates[i]=candidates[i-1] 表示排序后的数组，相邻相同的树；然后再判断是否被使用过
                //没有used，则无法判断是树枝重复还是树层重复，这里树枝重复是被允许的，不会导致元素被重复使用。
            }
            //不使用used，直接用startIndex去重
            //if(i > index && candidates[i] == candidates[i-1]) continue;

            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            back(candidates, sum, target, i + 1, used);//不用i+1了，表示可以重复读取当前的数
            sum -= candidates[i];
            path.pop_back();
            used[i] = false;
        }

    }//树枝是可以重复的，树层去重

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        if (candidates.size() == 0)
            return res;
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        back(candidates, 0, target, 0, used);
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
    vector<int> arr = { 10,1,2,7,6,1,5 };
    vector<vector<int>> res = s->combinationSum2(arr, 7);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}
