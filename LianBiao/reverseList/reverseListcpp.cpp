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
        _dummyHead = new ListNode(0); // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
        _size = 0;
    }
    Solution(ListNode *p) {
        _dummyHead = p; // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
        _size = 0;
    }

     ListNode* reverseList(ListNode* head) {
        //ListNode* temp; // ����cur����һ���ڵ�
        //ListNode* cur = head;
        //ListNode* pre = NULL;
        //while (cur) {
        //    temp = cur->next;  // ����һ�� cur����һ���ڵ㣬��Ϊ������Ҫ�ı�cur->next
        //    cur->next = pre; // ��ת����
        //    // ����pre �� curָ��
        //    pre = cur;
        //    cur = temp;
        //}
        //return pre;
         //�ȿ���ֻ�������ڵ���������ڵ�����  
         if (head == NULL) return NULL;
         if (head->next == NULL) return head;

         // �ݹ���ã���ת�ڶ����ڵ㿪ʼ���������
         ListNode* last = reverseList(head->next);
         // ��תͷ�ڵ���ڶ����ڵ��ָ��
         head->next->next = head;
         // ��ʱ�� head �ڵ�Ϊβ�ڵ㣬next ��Ҫָ�� NULL
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
        // ��Ե�����ж�
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        // �ݹ���ã���ת�ڶ����ڵ㿪ʼ���������
        ListNode* last = reverseList(head->next);
        // ��תͷ�ڵ���ڶ����ڵ��ָ��
        head->next->next = head;
        // ��ʱ�� head �ڵ�Ϊβ�ڵ㣬next ��Ҫָ�� NULL
        head->next = NULL;
        return last;
    }
};

void test02() {

    vector<int> a = { 2,3,1,2,4,3 };


    //ListNode *qhead = (ListNode*)malloc(sizeof(ListNode));
    //qhead->next = NULL;
    //ListNode* Rear;  //����Rearʼ��ָ��β����㣬��ʼʱָ��ͷ���
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