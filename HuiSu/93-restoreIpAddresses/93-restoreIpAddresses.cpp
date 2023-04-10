#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//
//有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//
//例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。
//回溯算法 ；用递归控制for循环嵌套的数量
//for循环横向遍历，递归纵向遍历，回溯不断调整结果集。
class Solution {
private:
    //  startIndex表示深度/递归的深度 可以看作是行  i表示宽度/循环的次数，可以看作是列
    vector<string> result;// 记录结果
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string& s, int startIndex, int pointNum) {
        //最开始是"2.5.5.25511135"这个字符串的第四段不合法给return了,然后再是"2.5.52.5511135"。。。等等
        if (pointNum == 3) { // 逗点数量为3时，分隔结束  ，pointNum==3 也是树的深度
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        //回溯算法==暴力算法 所有结果都一一判断了
        //回溯的过程 就是把不合法的或者合法的结果都处理了，
        //合法的存入结果集并回溯然后再继续递归，不合法就直接回溯到上一循环再处理再判断是否合法
        for (int i = startIndex; i < s.size(); i++) {
            // [startIndex, i]  表示深度为startIndex,循环到了i个值，，这里的i起始值会随着深度的改变。
            if (isValid(s, startIndex, i)) 
            {   // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin() + i + 1, '.');  // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--;                         // 回溯
                s.erase(s.begin() + i + 1);         // 回溯删掉逗点
            }
            else break; // 不合法，直接结束本层循环
        }
    }
    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result; // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
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
    //仿函数  类做函数使用
   /* for_each(res.begin(), res.end(), print002<T>());
    cout << endl;*/

    //匿名函数
    for_each(res.begin(), res.end(), [](T val) { cout << val << ";" ;});
    cout << endl;
}
//打印二维数组
template<typename T>
void PrintVecofVec1(vector<vector<T>>& res) {
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
    Solution* s = new Solution();
    string in = "25525511135";
    vector<string> res = s->restoreIpAddresses(in);
    print_vector_str<string>(res);
    //PrintVecofVec1<string>(res);

}
int main()
{
    test();
    return 0;
}