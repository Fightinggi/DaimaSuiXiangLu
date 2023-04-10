#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

//回溯算法 ；用递归控制for循环嵌套的数量
//for循环横向遍历，递归纵向遍历，回溯不断调整结果集。
class Solution {
public:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

    vector<string> res;
    string s;
    void back(const string& digits, int index)
    {
        if (index == digits.size())
        {
            res.push_back(s);
            return;
        }

        int digit = digits[index] - '0';//得到string中index位置的数字
        string letters = letterMap[digit]; //得到digits第index下的数字对应的三个字母
        for (int i = 0; i < letters.size(); i++)
        {
            s.push_back(letters[i]);
            back(digits, index + 1);
            s.pop_back();
            //隐藏的回溯  是把下一个要递归的数据直接放进递归函数中执行判断，
            //back(digits, index + 1, s + letters[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        res.clear();
        if (digits.size() == 0)
            return res;
        back(digits, 0);
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
    string in = "23";
    vector<string> res = s->letterCombinations(in);
    print_vector_str(res);
}
int main()
{
    test();
    return 0;
}