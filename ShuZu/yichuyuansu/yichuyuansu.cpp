#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

void test02() {

    Solution s = Solution();
    vector<int> v = { 1,2,3,4,7,9,10 };
    int tar = 2;

    int ret = s.removeElement(v, tar);
    cout << ret << endl;
}

int main() {

    test02();

    system("pause");
    return 0;
}