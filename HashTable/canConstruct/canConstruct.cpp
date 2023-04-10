#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <unordered_set>
#include <unordered_map>
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
    bool canConstruct(string ransomNote, string magazine) {

        //暴力解法  -->  两个for
        //for (int i = 0; i < magazine.length(); i++) {
        //    for (int j = 0; j < ransomNote.length(); j++) {
        //        // 在ransomNote中找到和magazine相同的字符
        //        if (magazine[i] == ransomNote[j]) {
        //            ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
        //            break;
        //        }
        //    }
        //}
        //// 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
        //if (ransomNote.length() == 0) {
        //    return true;
        //}
        //return false;

        //解法二
        //记录字符串中字母出现的次数,索引 下标 来找元素值
        //记录ransomNote  有字母出现的所有次数没有被 -- 到0 ， 说明magazine  字母数不够
        int record[26] = { 0 };
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            record[ransomNote[i] - 'a']++;
        }

        for (int i = 0; i < magazine.length(); i++)
        {
            if (record[magazine[i] - 'a'] != 0)
            {
                record[magazine[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (record[i] != 0)
            {
                return false;
            }
        }
        return true;

        //解法三
        //记录magazine，用ransomNote去 - magazine  如果record出现负数，则ransomNote多， magazine不够
        int record[26] = { 0 };
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // 通过recode数据记录 magazine里各个字符出现次数
            record[magazine[i] - 'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j] - 'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;


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
    void operator()(int val) {
        cout << val << " ";
    }
};

void printvector(vector<int> res) {

    for_each(res.begin(), res.end(), print001());
    cout << endl;

}

void test02() {

    Solution* so = new Solution();
    vector<int> v1 = { 1, 2 };  //一个输入对应一个答案
    vector<int> v2 = { -2, -1 };  //一个输入对应一个答案
    vector<int> v3 = { -1, 2 };  //一个输入对应一个答案
    vector<int> v4 = { 0, 2 };  //一个输入对应一个答案
    int target = 13;

    int res = so->fourSumCount(v1, v2, v3, v4);
    cout << res << endl;
    //printvector(res);

}

int main() {

    test02();

    system("pause");
    return 0;
}