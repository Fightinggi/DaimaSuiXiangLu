#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//�����ⷨ
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // ʹ��vector����һ����ά����
        int startx = 0, starty = 0; // ����ÿѭ��һ��Ȧ����ʼλ��
        int loop = n / 2; // ÿ��Ȧѭ�����Σ�����nΪ����3����ôloop = 1 ֻ��ѭ��һȦ�������м��ֵ��Ҫ��������
        int mid = n / 2; // �����м��λ�ã����磺nΪ3�� �м��λ�þ���(1��1)��nΪ5���м�λ��Ϊ(2, 2)
        int count = 1; // ������������ÿһ���ո�ֵ
        int offset = 1; // ��Ҫ����ÿһ���߱����ĳ��ȣ�ÿ��ѭ���ұ߽�����һλ
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;

            // ���濪ʼ���ĸ�for����ģ��ת��һȦ
            // ģ��������д�����(����ҿ�)
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // ģ��������д��ϵ���(����ҿ�)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // ģ��������д��ҵ���(����ҿ�)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // ģ��������д��µ���(����ҿ�)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // �ڶ�Ȧ��ʼ��ʱ����ʼλ��Ҫ���Լ�1�� ���磺��һȦ��ʼλ����(0, 0)���ڶ�Ȧ��ʼλ����(1, 1)
            startx++;
            starty++;

            // offset ����ÿһȦ��ÿһ���߱����ĳ���
            offset += 1;
        }

        // ���nΪ�����Ļ�����Ҫ�������������м��λ�ø�ֵ
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};


void test02() {

    Solution s = Solution();
    vector<int> v = { 2,3,1,2,4,3 };
    int tar = 7;

    vector<vector<int>> ret = s.generateMatrix(tar);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    test02();

    system("pause");
    return 0;
}