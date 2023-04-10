#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//���д���ַ�����д�ң���Ҫ����Ϊ������Ķ���û�������������Ķ�����ǲ�������
//Ҫ�ڶ��ֲ��ҵĹ����У����ֲ�������������whileѰ����ÿһ�α߽�Ĵ���Ҫ��ָ�������Ķ����������������ѭ������������
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // ����target������ұյ������[left, right]
        while (left <= right) { // ��left==right������[left, right]��Ȼ��Ч�������� <=
            int middle = left + ((right - left) / 2);// ��ֹ��� ��ͬ��(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target �������䣬����[left, middle - 1]
            }
            else if (nums[middle] < target) {
                left = middle + 1; // target �������䣬����[middle + 1, right]
            }
            else { // nums[middle] == target
                return middle; // �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
            }
        }
        // δ�ҵ�Ŀ��ֵ
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