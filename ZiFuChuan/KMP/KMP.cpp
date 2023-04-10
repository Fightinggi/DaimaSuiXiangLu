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
        int j = 0;//表示字串 前缀末尾,又表示这个子串的最长相等前后缀的长度
        next[0] = j;
        for (int i = 1; i < s.size(); i++) //i表示子串  后缀末尾
        {
            //不相等 利用next回退
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
            }

            if (s[i] == s[j])  //相等的情况
            {
                j++;

            }
            next[i] = j;
        }
    }
    //c++中不允许使用变量作为数组的长度定义数组，必须为常量值，
    //c++中所有的内存需求都是在程序执行前通过定义的常量来确定的。
    //c++中使用关键字new来进行动态内存申请，它是基于类型进行的，使用关键字delete进行内存释放
    int strStr(string haystack, string needle) {

        if (needle.size() == 0)
        {
            return 0;
        }

        int *Next_kmp = new int[needle.size()];  //前缀表
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
            if (j == needle.size())  // 文本串s里出现了模式串t
            {
                return i - (needle.size() - 1);  //返回起始位置
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
        ListNode* p = new ListNode(a[i]);   //申请新的结点 
        cur->next = p;
        cur = p;   //更新尾部指针 
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