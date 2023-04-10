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
                st.pop(); // s �� st.top()��ȵ����
            }
        }
        string result = "";
        while (!st.empty()) { // ��ջ��Ԫ�طŵ�result�ַ�������
            result += st.top();  //ac
            st.pop();
        }
        reverse(result.begin(), result.end()); // ��ʱ�ַ�����Ҫ��תһ��  ca
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