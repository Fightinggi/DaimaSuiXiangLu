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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }   
            else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

void test02() {

    Solution s = Solution();
    vector<int> a = { 2,3,1,2,4,3 };
    int len = 7;
    ListNode* qhead = new ListNode(0);
    ListNode* cur = qhead;

    //ListNode *qhead = (ListNode*)malloc(sizeof(ListNode));
    //qhead->next = NULL;
    //ListNode* Rear;  //定义Rear始终指向尾部结点，开始时指向头结点
    //Rear = qhead;
    for (int i = 0; i < len; i++)
    {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));   //申请新的结点 
        p->val = a[i];
        cur->next = p;
        cur = p;   //更新尾部指针 
    }
    cur -> next = NULL;

    ListNode* p = s.removeElements(qhead,1);

    while (p != NULL) {
        printf("%d,", p->val);
        p = p->next;
    }

    /*for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << endl;
}

int main() {

    test02();

    system("pause");
    return 0;
}