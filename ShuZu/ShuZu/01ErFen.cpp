#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//大家写二分法经常写乱，主要是因为对区间的定义没有想清楚，区间的定义就是不变量。
//要在二分查找的过程中，保持不变量，就是在while寻找中每一次边界的处理都要坚持根据区间的定义来操作，这就是循环不变量规则。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            }
            else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            }
            else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};

void test02() {

    Solution s = Solution();
    vector<int> v = { 1,2,3,4,7,9,10 };
    int tar = 2;

    int ret = s.search(v, tar);
    cout << ret << endl;
}

int main() {

    test02();

    system("pause");
    return 0;
}