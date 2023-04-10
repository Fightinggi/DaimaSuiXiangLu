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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // ����һ������ͷ���
        dummyHead->next = head; // ������ͷ���ָ��head���������������ɾ������
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // ��¼��ʱ�ڵ�
            ListNode* tmp1 = cur->next->next->next; // ��¼��ʱ�ڵ�

            cur->next = cur->next->next;    // ����һ
            cur->next->next = tmp;          // �����
            cur->next->next->next = tmp1;   // ������

            cur = cur->next->next; // cur�ƶ���λ��׼����һ�ֽ���
        }
        return dummyHead->next;
    }
};

void test02() {

    Solution s = Solution();
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

    ListNode* p = s.swapPairs(qhead);

    while (p != NULL) {
        printf("%d,", p->val);
        p = p->next;
    }
    cout << endl;
}

int main() {

    test02();

    system("pause");
    return 0;
}