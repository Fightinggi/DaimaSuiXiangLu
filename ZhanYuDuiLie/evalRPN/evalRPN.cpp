#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 力扣修改了后台测试数据，需要用longlong
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            }
            else {
                st.push(stoll(tokens[i]));//字符串转换为long long int
            }
        }

        int result = int(st.top());
        st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
        return result;
    }
};

void test()
{
    Solution so = Solution();
    vector<string> s = { "2","1","+","3","*" };
    /*string str[] = {"2","1","+","3","*" };
    vector<string> strArray(str, str + 10);*/

    int res = so.evalRPN(s);
    cout << res << endl;


}

int main()
{
    test();

    //system("pause");
    return 0;
}