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


        // //���ַ�����������

        // if(s.length() != t.length()){
        //     return false;
        // }
        // else{

        //     sort(s.begin(),s.end());
        //     sort(t.begin(),t.end());

        //     return s==t;

        // }

        //�����ֵ䣬s�ַ���++���ֵĴ���������t��--�ֵ���ֵĴ���
        int record[26] = { 0 };//�õ�����  ֻ��26����ĸ  0-25�±꼴Ϊa-z  
        int len = s.length();
        if (len != t.length()) {
            return false;
        }
        else {
            for (int i = 0; i < len; i++) {
                //��record����� ��ĸ���ֵĴ���
                record[s[i] - 'a']++; //���s[i]Ϊa����record[0] += 1; ���s[i]Ϊb����record[1] += 1; 
            }
            for (int i = 0; i < len; i++) {
                //��record��ȥ��ͬ�Ĳ���
                record[t[i] - 'a']--;
            }
            //�ж�����������ֵ�Ƿ�Ϊ0����ͬ����ͬ
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