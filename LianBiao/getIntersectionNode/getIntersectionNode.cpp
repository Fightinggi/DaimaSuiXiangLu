#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL) { // ������A�ĳ���
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL) { // ������B�ĳ���
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // ��curAΪ������ͷ��lenAΪ�䳤��
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        // �󳤶Ȳ�
        int gap = lenA - lenB;
        // ��curA��curB��ͬһ����ϣ�ĩβλ�ö��룩
        while (gap--) {
            curA = curA->next;
        }
        // ����curA �� curB��������ͬ��ֱ�ӷ���
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
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

    Solution s = Solution();
    ListNode* qheada = getlidtnode();
    ListNode* qheadb = getlidtnode();
    ListNode* p = s.getIntersectionNode(qheada,qheadb);
    printlistnode(p);

}

int main() {

    test02();

    system("pause");
    return 0;
}