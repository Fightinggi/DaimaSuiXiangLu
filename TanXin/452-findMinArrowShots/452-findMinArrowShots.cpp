#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
// 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，
//因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。

// 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且
//满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

// 给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。

// 示例 1：

// 输入：points = [[10,16],[2,8],[1,6],[7,12]]
// 输出：2
// 解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int res = 1;  // points 不为空至少需要一支箭
        for (int i = 1; i < points.size(); i++)
        {
            //如果无重叠，箭+1，无重叠：最小右边界小于下一位得左边界
            //如果重叠，更新最小右边界,不更新，则照顾不到右边小得气球
            if (points[i - 1][1] < points[i][0])
            {
                res++;
            }
            else
            {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
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
    int res = obj->findMinArrowShots(people);
    cout << res << endl;
    //PrintVecofVec2(res);

}
int main()
{
    test();
    return 0;
}