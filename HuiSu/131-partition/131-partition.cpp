#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//
//返回 s 所有可能的分割方案。
//
//示例 : 输入: "aab" 输出 : [["aa", "b"], ["a", "a", "b"]]
//回溯算法 ；用递归控制for循环嵌套的数量
//for循环横向遍历，递归纵向遍历，回溯不断调整结果集。
class Solution {
public:

    //存放结果
    vector<string> path;
    vector<vector<string>> res;
    //回溯函数
    void back(const string& s, int start_index)
    {
        //终止条件
        if (start_index >= s.size())
        {
            res.push_back(path);
            return;
        }

        //单层搜索
        for (int i = start_index; i < s.size(); i++)
        {
            if (isPalindrome(s, start_index, i))//如果是回文串
            {
                // 获取[startIndex,i]在s中的子串
                string str = s.substr(start_index, i - start_index + 1);
                path.push_back(str);
            }
            else
            {
                continue; // 不是回文，跳过
            }
            back(s, i + 1);// 寻找i+1为起始位置的子串
            path.pop_back();
        }

    }

    //判断回文
    bool isPalindrome(const string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        if (s.size() == 0)
            return res;
        back(s, 0);
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
    //仿函数  类做函数使用
   /* for_each(res.begin(), res.end(), print002<T>());
    cout << endl;*/

    //匿名函数
    for_each(res.begin(), res.end(), [](T val) { cout << val << " "; });
    cout << endl;
}
//打印二维数组
//template<typename T>
//void printvector2(vector<vector<T>>& A) {
//    for (vector<vector<T>>::iterator i = A.begin(); i != A.end(); i++) {
//        for (vector<T>::iterator j = i->begin(); j != i->end(); j++) {
//            cout << *j << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
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
    string in = "aab";
    vector<vector<string>> res = s->partition(in);
    PrintVecofVec1<string>(res);

}
int main()
{
    test();
    return 0;
}