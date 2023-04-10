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

        //�����ⷨ  -->  ����for
        //for (int i = 0; i < magazine.length(); i++) {
        //    for (int j = 0; j < ransomNote.length(); j++) {
        //        // ��ransomNote���ҵ���magazine��ͬ���ַ�
        //        if (magazine[i] == ransomNote[j]) {
        //            ransomNote.erase(ransomNote.begin() + j); // ransomNoteɾ������ַ�
        //            break;
        //        }
        //    }
        //}
        //// ���ransomNoteΪ�գ���˵��magazine���ַ��������ransomNote
        //if (ransomNote.length() == 0) {
        //    return true;
        //}
        //return false;

        //�ⷨ��
        //��¼�ַ�������ĸ���ֵĴ���,���� �±� ����Ԫ��ֵ
        //��¼ransomNote  ����ĸ���ֵ����д���û�б� -- ��0 �� ˵��magazine  ��ĸ������
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

        //�ⷨ��
        //��¼magazine����ransomNoteȥ - magazine  ���record���ָ�������ransomNote�࣬ magazine����
        int record[26] = { 0 };
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // ͨ��recode���ݼ�¼ magazine������ַ����ִ���
            record[magazine[i] - 'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // ����ransomNote����record���Ӧ���ַ�������--����
            record[ransomNote[j] - 'a']--;
            // ���С����˵��ransomNote����ֵ��ַ���magazineû��
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
    vector<int> v1 = { 1, 2 };  //һ�������Ӧһ����
    vector<int> v2 = { -2, -1 };  //һ�������Ӧһ����
    vector<int> v3 = { -1, 2 };  //һ�������Ӧһ����
    vector<int> v4 = { 0, 2 };  //һ�������Ӧһ����
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