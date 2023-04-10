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
    vector<int> twoSum(vector<int>& nums, int target) {
        //���� �ⷨ
        // vector<int> res;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size()-i;j++){
        //         if((nums[i]+nums[j])==target){
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }
        //     }
        // }
        // return res;

        //��ϣmap
        std::unordered_map <int, int> map;
        //key������ֵ��value���±꣬��Ϊ��Ѱ���Ƿ����ĳ��ֵ ʱ��Ԫ��ֵ��
        for (int i = 0; i < nums.size(); i++) {

            auto iter = map.find(target - nums[i]);
            //�ж��Ƿ����target-nums[i]?����[i, map.value] : map.insert(key=nums[i],value=i)
            if (iter != map.end())
            {
                return { iter->second, i };
            }
            else {
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
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

    Solution *so = new Solution();
    vector<int> v1 = { 1,2,7,11,2 };  //һ�������Ӧһ����
    int target = 13;

    vector<int> res = so->twoSum(v1, target);
    printvector(res);

}

int main() {

    test02();

    system("pause");
    return 0;
}