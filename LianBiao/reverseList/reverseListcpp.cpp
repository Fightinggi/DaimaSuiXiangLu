#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val) :val(val), next(nullptr) {}
    };

    Solution() {
        _dummyHead = new ListNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }
    Solution(ListNode *p) {
        _dummyHead = p; // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

     ListNode* reverseList(ListNode* head) {
        //ListNode* temp; // 保存cur的下一个节点
        //ListNode* cur = head;
        //ListNode* pre = NULL;
        //while (cur) {
        //    temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
        //    cur->next = pre; // 翻转操作
        //    // 更新pre 和 cur指针
        //    pre = cur;
        //    cur = temp;
        //}
        //return pre;
         //先考虑只有两个节点的情况，多节点的情况  
         if (head == NULL) return NULL;
         if (head->next == NULL) return head;

         // 递归调用，翻转第二个节点开始往后的链表
         ListNode* last = reverseList(head->next);
         // 翻转头节点与第二个节点的指向
         head->next->next = head;
         // 此时的 head 节点为尾节点，next 需要指向 NULL
         head->next = NULL;
         return last;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    void printLinkedList() {
        ListNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    ListNode* _dummyHead=NULL;
    int _size;
};
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) :val(val), next(nullptr) {}
};
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        // 边缘条件判断
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        // 递归调用，翻转第二个节点开始往后的链表
        ListNode* last = reverseList(head->next);
        // 翻转头节点与第二个节点的指向
        head->next->next = head;
        // 此时的 head 节点为尾节点，next 需要指向 NULL
        head->next = NULL;
        return last;
    }
};

void test02() {

    vector<int> a = { 2,3,1,2,4,3 };


    //ListNode *qhead = (ListNode*)malloc(sizeof(ListNode));
    //qhead->next = NULL;
    //ListNode* Rear;  //定义Rear始终指向尾部结点，开始时指向头结点
    //Rear = qhead;
    Solution* my_ll = new Solution();
    for (int i = 0; i < a.size(); i++)
    {
        my_ll->addAtTail(a[i]);
    }

    my_ll->printLinkedList();

    Solution* my_l2 = new Solution();
    Solution::ListNode* tmp = my_l2->reverseList(my_ll->_dummyHead);


    my_ll = new Solution(tmp);
    my_ll->printLinkedList();

}

int main() {

    test02();

    system("pause");
    return 0;
}