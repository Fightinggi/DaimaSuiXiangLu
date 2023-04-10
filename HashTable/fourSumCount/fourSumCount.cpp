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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        //(a+b)+(c+d) = 0
        //(a+b) = 0-(c+d)

        unordered_map<int, int> umap;

        for (int a : nums1)
        {
            for (int b : nums2)
            {
                umap[a + b] ++;//key Ϊa+b  valueΪ���ֵĴ���
            }
        }

        int count = 0;//ͳ�Ƴ���(a+b)+(c+d) = 0�Ĵ���

        for (int c : nums3)
        {
            for (int d : nums4)
            {
                if (umap.find(0 - (c + d)) != umap.end())
                {
                    //�����map���ҵ���ӳ���ֵ,���ֵĴ���  ���Ǻ�0 ���ֵĴ�����
                    count = count + umap[0 - (c + d)];
                }
            }
        }
        return count;


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

    int res = so->fourSumCount(v1, v2,v3,v4);
    cout << res << endl;
    //printvector(res);

}

int main() {

    test02();

    system("pause");
    return 0;
}