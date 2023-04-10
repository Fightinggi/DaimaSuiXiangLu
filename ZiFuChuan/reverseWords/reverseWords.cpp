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

    // 移除多余空格  移除元素 ’ ‘  快慢指针
    // 将整个字符串反转
    // 将每个单词反转

    void reverse(string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s)  //移除’‘元素
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < s.size(); fastIndex++)
        {
            // 遇到非' ' 则处理 新数组 
            if (s[fastIndex] != ' ')
            {
                // 留空格
                if (slowIndex != 0)
                {
                    s[slowIndex] = ' ';
                    //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                    slowIndex++;
                }
                while (fastIndex < s.size() && s[fastIndex] != ' ')
                {
                    s[slowIndex] = s[fastIndex];  //补上该单词，遇到空格说明单词结束。
                    slowIndex++;
                    fastIndex++;
                }
            }
        }
        s.resize(slowIndex);
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
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

    string str2 = so.reverseWords(str1);  //happy are We
    printstirng(str2);
}

int main() {

    test02();

    system("pause");
    return 0;
}