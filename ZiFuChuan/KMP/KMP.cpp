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
    void getNext(int* next, const string& s)
    {
        int j = 0;//��ʾ�ִ� ǰ׺ĩβ,�ֱ�ʾ����Ӵ�������ǰ��׺�ĳ���
        next[0] = j;
        for (int i = 1; i < s.size(); i++) //i��ʾ�Ӵ�  ��׺ĩβ
        {
            //����� ����next����
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1]; // ע�������Ҫ��ǰһλ�Ķ�Ӧ�Ļ���λ����
            }

            if (s[i] == s[j])  //��ȵ����
            {
                j++;

            }
            next[i] = j;
        }
    }
    //c++�в�����ʹ�ñ�����Ϊ����ĳ��ȶ������飬����Ϊ����ֵ��
    //c++�����е��ڴ��������ڳ���ִ��ǰͨ������ĳ�����ȷ���ġ�
    //c++��ʹ�ùؼ���new�����ж�̬�ڴ����룬���ǻ������ͽ��еģ�ʹ�ùؼ���delete�����ڴ��ͷ�
    int strStr(string haystack, string needle) {

        if (needle.size() == 0)
        {
            return 0;
        }

        int *Next_kmp = new int[needle.size()];  //ǰ׺��
        getNext(Next_kmp, needle);
        int j = 0;

        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = Next_kmp[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())  // �ı���s�������ģʽ��t
            {
                return i - (needle.size() - 1);  //������ʼλ��
            }
        }

        delete[] Next_kmp;
        return -1;
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

    int str2 = so.strStr(str1, "are");
    cout << str2 << endl;
    //printstirng(str2);
}

int main() {

    test02();

    system("pause");
    return 0;
}