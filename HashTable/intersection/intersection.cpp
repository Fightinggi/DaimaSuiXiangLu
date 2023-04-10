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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        //排序加双指针

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> vec;

        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] == nums2[j]) {//两集合中相同的数值，保存
                //添加到集合
                if (find(vec.begin(), vec.end(), nums1[i]) == vec.end()) {
                    vec.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j]) { //排序后，小的值向前走一位，
                j++;
            }
            else {
                i++;
            }
        }
        return vec;

        //unordered_set
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());


        //数组来做哈希表
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集         去重
        int hash[1005] = { 0 }; // 默认数值为0
        for (int num : nums1) { // nums1中出现的字母在hash数组中做          记录
            hash[num] = 1;
        }
        for (int num : nums2) { // nums2中出现话，result记录
            if (hash[num] == 1) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());

    }
};

ListNode* getlidtnode() {

    vector<int> a = { 2,3,1,2,4,3 };
    ListNode* qhead = new ListNode(a[0]);
    ListNode* cur = qhead;

    for (int i = 1; i < a.size(); i++)
    {
        ListNode* p = new ListNode(a[i]);   //申请新的结点 
        cur->next = p;
        cur = p;   //更新尾部指针 
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

    Solution so = Solution();
    vector<int> a1 = { 4,9,5 };
    vector<int> a2 = { 9,4,9,8,4 };

    vector<int> res = so.intersection(a1, a2);

    printvector(res);


}

int main() {

    test02();

    system("pause");
    return 0;
}