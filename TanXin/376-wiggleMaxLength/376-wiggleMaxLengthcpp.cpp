#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。
//
//例如，[1, 7, 4, 9, 2, 5] 是一个摆动序列，因为差值(6, -3, 5, -7, 3) 是正负交替出现的。
//相反, [1, 4, 7, 2, 5] 和[1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
using namespace std;
class Solution {
public:
    // = 情况一上下中间有平坡
    //最大值nums[i]-nums[i-1] >= 0  && nums[i+1] - nums[i] < 0
    //最小值nums[i]-nums[i-1] <= 0  && nums[i+1] - nums[i] > 0
    //当只有两个数的时候，在最前面加一位与nums[0]相同的数 {1，1，2}

    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int pre = 0; // 记录前一个方向，只有改变方向的时候，才对pre更新
        int cur = 0; // 记录下一个放向
        int res = 1; // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++)
        {
            cur = nums[i + 1] - nums[i];
            if ((cur < 0 && pre >= 0) || (cur > 0 && pre <= 0))
            {
                res++;
                pre = cur;// 注意这里，只在摆动变化的时候更新prediff 
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
    vector<int> g = { 1,17,5,10,13,15,10,5,16,8 };

    int res = obj->wiggleMaxLength(g);
    cout << res <<  endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}