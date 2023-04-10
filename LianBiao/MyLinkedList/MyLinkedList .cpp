#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class MyLinkedList {
public:
    // ��������ڵ�ṹ��
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) :val(val), next(nullptr) {}
    };

    // ��ʼ������
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
        _size = 0;
    }

    // ��ȡ����index���ڵ���ֵ�����index�ǷǷ���ֱֵ�ӷ���-1�� ע��index�Ǵ�0��ʼ�ģ���0���ڵ����ͷ���
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while (index--) { // ���--index �ͻ�������ѭ��
            cur = cur->next;
        }
        return cur->val;
    }

    // ��������ǰ�����һ���ڵ㣬������ɺ��²���Ľڵ�Ϊ������µ�ͷ���
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;  //���³�ʼ������ͷ�ڵ�
        _size++;
    }

    // ��������������һ���ڵ�
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // �ڵ�index���ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
    // ���index ��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β���
    // ���index��������ĳ��ȣ��򷵻ؿ�
    // ���indexС��0������ͷ������ڵ�
    void addAtIndex(int index, int val) {

        if (index > _size) return;
        if (index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // ɾ����index���ڵ㣬���index ���ڵ�������ĳ��ȣ�ֱ��return��ע��index�Ǵ�0��ʼ��
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    // ��ӡ����
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    LinkedNode* _dummyHead;

};

void test02() {

    MyLinkedList *my_ll = new MyLinkedList();
    
    my_ll->addAtHead(1);
    my_ll->addAtTail(3);
    my_ll->addAtIndex(1, 2);
    my_ll->printLinkedList();
    int r = my_ll->get(1); cout << r << endl;
    my_ll->deleteAtIndex(2);
    my_ll->printLinkedList();

    delete my_ll;

}

int main() {

    test02();

    system("pause");
    return 0;
}