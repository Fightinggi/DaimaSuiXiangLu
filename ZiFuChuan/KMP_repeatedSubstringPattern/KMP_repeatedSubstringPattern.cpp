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
    bool repeatedSubstringPattern(string s) {

        if (s.size() == 0)
        {
            return 0;
        }

        int *next = new int[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
            //最大前后缀相等长度在字符串的最后一位索引对应的next数组值next[len-1]
            // (len-next[len-1])  表示去除最大...子串的剩余字符串，
            // len%(len-next[len-1])==0  说明这个子串能重复构成s
        {
            return true;
        }
        delete[] next;
        return false;

    }
    // 拼接 匹配 
    //bool repeatedSubstringPattern(string s) {
    //    string t = s + s;
    //    t.erase(t.begin()); t.erase(t.end() - 1); // 掐头去尾
    //    if (t.find(s) != std::string::npos) return true; // r
    //    return false;
    //}
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
    string str3 = "abababc";

    int str2 = so.repeatedSubstringPattern(str3);
    cout << str2 << endl;
    //printstirng(str2);
}

int main() {

    test02();

    system("pause");
    return 0;
}