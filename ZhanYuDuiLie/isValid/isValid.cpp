#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // ���s�ĳ���Ϊ������һ��������Ҫ��
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // ����������������ַ���ƥ��Ĺ����У�ջ�Ѿ�Ϊ���ˣ�û��ƥ����ַ��ˣ�˵��������û���ҵ���Ӧ�������� return false
            // �ڶ�������������ַ���ƥ��Ĺ����У�����ջ��û������Ҫƥ����ַ�������return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() �� s[i]��ȣ�ջ����Ԫ��
        }
        // ��һ���������ʱ�����Ѿ����������ַ���������ջ��Ϊ�գ�˵������Ӧ��������û����������ƥ�䣬����return false�������return true
        return st.empty();
    }
};

void test()
{
    string s = "(){}{}[]";
    Solution so = Solution();

    int res = so.isValid(s);
    cout << res << endl;


}

int main()
{
    test();

	//system("pause");
	return 0;
}