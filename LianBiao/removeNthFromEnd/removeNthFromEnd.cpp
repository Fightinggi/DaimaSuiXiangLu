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
    ListNode* removeNthFromEnd(ListNode* head, int n=2) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while (n-- && fast != NULL) {  //fast����n����Ϊʲô��n�����𣺵�fast����NULLʱ��ǰn������Ҫɾ���Ľڵ�
            fast = fast->next;
        }
        fast = fast->next; // fast����ǰ��һ������Ϊ��Ҫ��slowָ��ɾ���ڵ����һ���ڵ�
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        // ListNode *tmp = slow->next;  C++�ͷ��ڴ���߼�
        // slow->next = tmp->next;
        // delete nth;

        return dummyHead->next;
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
    ListNode* qhead = getlidtnode();
    ListNode* p = s.removeNthFromEnd(qhead);
    printlistnode(p);
    
}

int main() {

    test02();

    system("pause");
    return 0;
}