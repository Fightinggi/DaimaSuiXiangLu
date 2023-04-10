#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
#include <algorithm>
//给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 - A[i]，然后总共重复这个过程 K 次。
// （我们可以多次选择同一个索引 i。）
//
//以这种方式修改数组后，返回数组可能的最大和。
//
//示例 1：
//
//输入：A = [4, 2, 3], K = 1
//输出：5
//解释：选择索引(1, ) ，然后 A 变为[4, -2, 3]。
using namespace std;
class Solution {

    //第一步：将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
    //第二步：从前向后遍历，遇到负数将其变为正数，同时K--
    //第三步：如果K还大于0，那么反复转变数值最小的元素，将K用完
    //第四步：求和
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步  5，-4，-3，2，-1
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // 第三步
        int result = 0;
        for (int a : A) result += a;        // 第四步
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
    vector<int> g = { 2,-3,-1,5,-4 };

    int res = obj->largestSumAfterKNegations(g,1);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}