#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:

    // �Ƴ�����ո�  �Ƴ�Ԫ�� �� ��  ����ָ��
    // �������ַ�����ת
    // ��ÿ�����ʷ�ת

    void reverse(string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s)  //�Ƴ�����Ԫ��
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < s.size(); fastIndex++)
        {
            // ������' ' ���� ������ 
            if (s[fastIndex] != ' ')
            {
                // ���ո�
                if (slowIndex != 0)
                {
                    s[slowIndex] = ' ';
                    //�ֶ����ƿո񣬸�����֮����ӿո�slow != 0˵�����ǵ�һ�����ʣ���Ҫ�ڵ���ǰ��ӿո�
                    slowIndex++;
                }
                while (fastIndex < s.size() && s[fastIndex] != ' ')
                {
                    s[slowIndex] = s[fastIndex];  //���ϸõ��ʣ������ո�˵�����ʽ�����
                    slowIndex++;
                    fastIndex++;
                }
            }
        }
        s.resize(slowIndex);
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); //ȥ������ո񣬱�֤����֮��ֻ֮��һ���ո����ַ�����βû�ո�
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces��֤��һ�����ʵĿ�ʼ�±�һ����0��
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //����ո���ߴ�β��˵��һ�����ʽ��������з�ת��
                reverse(s, start, i - 1); //��ת��ע��������ұ� []�ķ�ת��
                start = i + 1; //������һ�����ʵĿ�ʼ�±�start
            }
        }
        return s;

    }
};

ListNode* getlidtnode() {

    vector<int> a = { 2,3,1,2,4,3 };
    ListNode* qhead = new ListNode(a[0]);
    ListNode* cur = qhead;

    for (int i = 1; i < a.size(); i++)
    {
        ListNode* p = new ListNode(a[i]);   //�����µĽ�� 
        cur->next = p;
        cur = p;   //����β��ָ�� 
    }
    cur->next = NULL;
    return qhead;
}

void printlistnode(ListNode* p) {
    while (p != NULL) {
        printf("%d,", p->val);
        p = p->next;
    }
    cout << endl;

}

struct print001 {
    void operator()(string val) {
        cout << val << " ";
    }
};

void printvector(vector<string> res) {

    for_each(res.begin(), res.end(), print001());
    cout << endl;

}
void printstirng(string res) {

    for (int i = 0; i < res.size(); i++) {

        cout << res[i];
    }
    cout << endl;
}
void test02() {

    Solution so = Solution();
    vector<string> s = { "h","e","l","l","o" };

    string str1 = "We are happy";

    string str2 = so.reverseWords(str1);  //happy are We
    printstirng(str2);
}

int main() {

    test02();

    system("pause");
    return 0;
}