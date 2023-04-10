#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char s : S) {
            if (st.empty() || s != st.top()) {
                st.push(s);
            }
            else {
                st.pop(); // s 与 st.top()相等的情况
            }
        }
        string result = "";
        while (!st.empty()) { // 将栈中元素放到result字符串汇总
            result += st.top();  //ac
            st.pop();
        }
        reverse(result.begin(), result.end()); // 此时字符串需要反转一下  ca
        return result;

    }
};

void test()
{
    string s = "abbaca";
    Solution so = Solution();

    string res = so.removeDuplicates(s);
    cout << res << endl;


}

int main()
{
    test();

    //system("pause");
    return 0;
}