#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
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
    bool isAnagram(string s, string t) {


        // //两字符串排序后相等

        // if(s.length() != t.length()){
        //     return false;
        // }
        // else{

        //     sort(s.begin(),s.end());
        //     sort(t.begin(),t.end());

        //     return s==t;

        // }

        //定义字典，s字符串++出现的次数，遍历t，--字典出现的次数
        int record[26] = { 0 };//用的数组  只有26种字母  0-25下标即为a-z  
        int len = s.length();
        if (len != t.length()) {
            return false;
        }
        else {
            for (int i = 0; i < len; i++) {
                //往record中添加 字母出现的次数
                record[s[i] - 'a']++; //如果s[i]为a，则record[0] += 1; 如果s[i]为b，则record[1] += 1; 
            }
            for (int i = 0; i < len; i++) {
                //对record除去相同的操作
                record[t[i] - 'a']--;
            }
            //判断数组中所有值是否为0？相同：不同
            for (int i = 0; i < 26; i++) {
                if (record[i] != 0) {
                    return false;
                }
            }
            return true;
        }
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

void test02() {

    Solution so = Solution();
    string s = "anagram";
    string t = "nagaram";

    bool b = so.isAnagram(s, t);

    cout << b << endl;
    

}

int main() {

    test02();

    system("pause");
    return 0;
}