#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <unordered_set>
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
    //���������
    int getsum(int n) {
        int sum = 0;
        while (n) {
            //ȡ���һλ����
            sum += (n % 10) * (n % 10);
            //ȡ����λ����
            n /= 10;
        }
        return sum;
    }

    //����ָ��   �������л�
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = getsum(slow);
            fast = getsum(fast);
            fast = getsum(fast);
            if (slow == fast)
                break;
        }
        return slow == 1;
    }

    // bool isHappy(int n) {
    //     //�ж��Ƿ�ѭ���������ظ�������set�е�ֵ �� ����false��true
    //     unordered_set<int> set;
    //     while(1){
    //         int sum = getsum(n);

    //         if(sum==1){
    //             return true;
    //         }
    //         if(set.find(sum) != set.end()){
    //             return false;

    //         }
    //         else{
    //             set.insert(sum);
    //         }

    //         n = sum;
    //     }
    // }
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




}

int main() {

    test02();

    system("pause");
    return 0;
}