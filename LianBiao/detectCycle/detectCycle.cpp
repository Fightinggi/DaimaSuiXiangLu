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
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // ����ָ��������
            if (slow == fast) {
                //��¼��ʼλ��head��������λ��slow == fast
                ListNode* index1 = fast;
                ListNode* index2 = head;
                //��ڵ���������ʼλ�õ���ڵ�Ľڵ���==����λ�õ���ڵ�Ľڵ�����x=zʱ��n=1
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // ���ػ������
            }
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
    ListNode* p = s.detectCycle(qheada);
    printlistnode(p);

}

int main() {

    test02();

    system("pause");
    return 0;
}