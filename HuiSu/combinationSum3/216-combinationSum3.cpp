#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//回溯算法 ；嵌套n个for循环
class Solution {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path; // 符合条件的结果
    void backtracking(int targetSum, int k, int sum, int startIndex) {  //==========startIndex 集合开始的位置============

        if (sum > targetSum) { // 剪枝操作
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }

        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) { // 剪枝
            sum += i; // 处理
            path.push_back(i); // 处理
            // if(sum>target) //剪枝处理
            // {
            //     sum-=i;  不能忘了 回溯
            //     path.pop_back();  回溯
            //     return;
            // }
            backtracking(targetSum, k, sum, i + 1); // 注意i+1调整startIndex  //index+1 表示再向下一层递归时，开始位置前进一位，不重复使用当前的数
            sum -= i; // 回溯
            path.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // 可以不加
        path.clear();   // 可以不加
        backtracking(n, k, 0, 1);
        return result;
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
    vector<vector<int>> res = s->combinationSum3(3, 9);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}