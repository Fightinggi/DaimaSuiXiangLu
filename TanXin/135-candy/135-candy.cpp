#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
//
//你需要按照以下要求，帮助老师给这些孩子分发糖果：
//
//每个孩子至少分配到 1 个糖果。
//相邻的孩子中，评分高的孩子必须获得更多的糖果。
//那么这样下来，老师至少需要准备多少颗糖果呢？
//
//示例 1:
//
//输入: [1, 0, 2]
//输出 : 5
//解释 : 你可以分别给这三个孩子分发 2、1、2 颗糖果。
using namespace std;
class Solution {
public:
    //这道题目一定是要确定一边之后，再确定另一边，例如比较每一个孩子的左边，然后再比较右边，如果两边一起考虑一定会顾此失彼。
    int candy(vector<int>& ratings) {

        vector<int> candyVec(ratings.size(), 1);

        //左到右，右大于左，candy+1，小于candy不变
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                candyVec[i] = candyVec[i - 1] + 1;  //比上一位递增一位
        }
        //右到左，左大于右，candy+1，小于candy不变
        for (int i = ratings.size() - 2; i > 0; i--)
        {
            if (ratings[i] > ratings[i + 1]) //全局最优：相邻的孩子中，评分高的右孩子获得比左边孩子更多的糖果
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
        }
        //统计结果
        int res = 0;
        for (int can : candyVec) res += can;
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
    vector<int> g = { 1,0,2 };
    vector<int> s = { 3,4,5,1,2 };

    int res = obj->candy(g);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}