#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
//
//请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
//
//示例 1：
//
//输入：people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
//输出： [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
//解释：
//编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
//编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
//编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
//编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
//编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
//编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
//因此 [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]] 是重新构造后的队列。
using namespace std;
//在135.分发糖果(opens new window)我就强调过一次，遇到两个维度权衡的时候，一定要先确定一个维度，再确定另一个维度。
//
//如果两个维度一起考虑一定会顾此失彼。
class Solution {
public:
    //people[i] = [hi, ki]
    // h相同 k从小到大
    // 身高h从大到小排序
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] == b[0])  return a[1] < b[1];
        return a[0] > b[0];
    }
    // 局部最优：优先按身高高的people的k来插入。插入操作过后的people满足队列属性
    // 全局最优：最后都做完插入操作，整个队列满足题目队列属性
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (auto p : people)
        {
            //个子小得往前插入，不会影响原来得排序队列属性
            if (p[1] < res.size())  //如果p[1]小于res数组，说明需要在中间插入，插入得位置由k决定
                res.insert(res.begin() + p[1], p);  //在p[1]得位置插入元素p
            else
                res.push_back(p);

        }
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
    vector<int> g = { 5,5,5,10,20 };
    vector<vector<int>> people = { {7,0} ,{4,4},{7,1},{5,0},{6,1},{5,2} };
    vector<vector<int>> res = obj->reconstructQueue(people);
    //cout << res << endl;
    PrintVecofVec2(res);

}
int main()
{
    test();
    return 0;
}