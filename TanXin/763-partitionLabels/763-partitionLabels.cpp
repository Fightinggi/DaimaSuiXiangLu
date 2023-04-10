#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
//
//示例：
//
//输入：S = "ababcbacadefegdehijhklij"
//输出：[9, 7, 8] 解释： 划分结果为 "ababcbaca", "defegde", "hijhklij"。 每个字母最多出现在一个片段中。 
//像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

class Solution {
public:
    vector<int> partitionLabels(string s) {

        //记录最后一个字母出现的位置
        int hash[27] = { 0 }; // 0-26下标 代表a-z
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;//更新字母的位置
        }

        vector<int> res;
        //遍历字符串，初始化起始位置，计算、判断终点位置
        int left = 0;
        int max_hash = 0; // 最远下标 
        for (int i = 0; i < s.size(); i++)
        {
            //记录更新出现最远下标 right
            //i遍历到 最远下标 即使分割点
            //更新终点位置left
            max_hash = max(max_hash, hash[s[i] - 'a']);// a 的最远下标8 
            if (i == max_hash)//局部最优，找到阶段内最远下标，阶段终止条件是最远下标同索引值相同
            {
                res.push_back(i - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};

//仿函数 打印一维数组 vector<string>
template<typename T>
struct print002 {
    void operator()(T val) {
        cout << val << " ";
    }
};
template<typename T>
void print_vector_str(vector<T> res)
{
    for_each(res.begin(), res.end(), print002<T>());
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
    vector<int> g = { 2,3,1,1,4 };
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = obj->partitionLabels(s);
    //cout << res << endl;
    print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}