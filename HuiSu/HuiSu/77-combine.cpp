#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void back(int n, int k, int start_index)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        //for (int i = start_index; i <= n - (k - path.size()) + 1; i++)     
        // k - path.size() <= n-i  剪枝操作  往后可循环的集合树小于要求的  就不用再循环了
        // 至多从n - (k - path.size()) + 1开始  因为从i=start_index=1开始的
        //剪枝 消耗   4ms   9.9mb
        //不剪枝 消耗 28ms  9.7mb
        for (int i = start_index; i <= n; i++)
        {
            path.push_back(i);
            back(n, k, i + 1);//递归
            path.pop_back();//回溯
        }

    }

    vector<vector<int>> combine(int n, int k) {

        back(n, k, 1);
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
    Solution *s = new Solution();
    vector<vector<int>> res = s->combine(4, 2);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}