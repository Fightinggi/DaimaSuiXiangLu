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
    string replaceSpace(string s) {
        int count = 0; // ͳ�ƿո�ĸ���
        int sOldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count++;
            }
        }
        // �����ַ���s�Ĵ�С��Ҳ����ÿ���ո��滻��"%20"֮��Ĵ�С
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        // �Ӻ���ǰ���ո��滻Ϊ"%20"
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            }
            else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
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

    string str2 = so.replaceSpace(str1);
    printstirng(str2);
}

int main() {

    test02();

    system("pause");
    return 0;
}