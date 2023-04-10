#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//�����ⷨ
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX; // ���յĽ��
        int sum = 0; // �����е���ֵ֮��
        int subLength = 0; // �����еĳ���
        for (int i = 0; i < nums.size(); i++) { // �������������Ϊi
            sum = 0;
            for (int j = i; j < nums.size(); j++) { // ������������ֹλ��Ϊj
                sum += nums[j];
                if (sum >= s) { // һ�����������кͳ�����s������result
                    subLength = j - i + 1; // ȡ�����еĳ���
                    result = result < subLength ? result : subLength;
                    break; // ��Ϊ�������ҷ���������̵������У�����һ������������break
                }
            }
        }
        // ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
        return result == INT32_MAX ? 0 : result;
    }
};

//��������
/*���ھ��� ������� �� s �ĳ�����С�� ���� �����顣

���ڵ���ʼλ������ƶ��������ǰ���ڵ�ֵ����s�ˣ����ھ�Ҫ��ǰ�ƶ��ˣ�Ҳ���Ǹ���С�ˣ���

���ڵĽ���λ������ƶ������ڵĽ���λ�þ��Ǳ��������ָ�룬Ҳ����forѭ���������*/

class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // ����������ֵ֮��
        int i = 0; // ����������ʼλ��
        int subLength = 0; // �������ڵĳ���
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // ע������ʹ��while��ÿ�θ��� i����ʼλ�ã��������ϱȽ��������Ƿ��������
            while (sum >= s) {
                subLength = (j - i + 1); // ȡ�����еĳ���
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // �������ֳ��������ڵľ���֮�������ϱ��i�������е���ʼλ�ã�
            }
        }
        // ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
        return result == INT32_MAX ? 0 : result;
    }
};

void test02() {

    Solution s = Solution();
    vector<int> v = { 2,3,1,2,4,3 };
    int tar = 7;

    int ret = s.minSubArrayLen(tar,v);
    cout << ret << endl;
}

int main() {

    test02();

    system("pause");
    return 0;
}