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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        //双指针法 三数之和 套一层for循环
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            //剪枝操作  同样也是第一位大于target时，
            if (nums[i] > target && nums[i] >= 0)
            {
                break;
            }
            //去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // b+c+d = target-nums[i]  三数之和
            for (int j = i + 1; j < nums.size(); j++)
            {
                //二级剪枝和去重
                if (nums[j] + nums[i] > target && (nums[j] + nums[i] >= 0 || target >= 0))
                {
                    break;
                }
                //去重
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                //双指针
                int left = j + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    if (nums[j] + nums[right] + nums[left] > target - nums[i]) right--;
                    else if (nums[j] + nums[right] + nums[left] < target - nums[i]) left++;
                    else
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[right], nums[left]});
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        right--;
                        left++;
                    }
                }

            }

        }
        return res;


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

void printvector2(vector<vector<int>>& A) {
    for (vector<vector<int>>::iterator i = A.begin(); i != A.end(); i++) {
        for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
}

void test02() {

    Solution* so = new Solution();
    vector<int> v1 = { 1,0,-1,0,-2,2 };  //一个输入对应一个答案
    int target = 0;

    vector<vector<int>> res = so->fourSum(v1,target);
    printvector2(res);

}

int main() {

    test02();

    system("pause");
    return 0;
}