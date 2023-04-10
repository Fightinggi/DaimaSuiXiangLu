#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j]) {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};

void test02() {

    Solution s = Solution();
    vector<int> v = { 1,2,3,4,7,9,10 };
    int tar = 2;

    vector<int> ret = s.sortedSquares(v);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ",";
    }
    cout << endl;
}

int main() {

    test02();

    system("pause");
    return 0;
}