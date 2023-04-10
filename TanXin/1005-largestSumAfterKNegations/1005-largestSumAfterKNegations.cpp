#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
#include <algorithm>
//����һ���������� A������ֻ�������·����޸ĸ����飺����ѡ��ĳ������ i ���� A[i] �滻Ϊ - A[i]��Ȼ���ܹ��ظ�������� K �Ρ�
// �����ǿ��Զ��ѡ��ͬһ������ i����
//
//�����ַ�ʽ�޸�����󣬷���������ܵ����͡�
//
//ʾ�� 1��
//
//���룺A = [4, 2, 3], K = 1
//�����5
//���ͣ�ѡ������(1, ) ��Ȼ�� A ��Ϊ[4, -2, 3]��
using namespace std;
class Solution {

    //��һ���������鰴�վ���ֵ��С�Ӵ�С����ע��Ҫ���վ���ֵ�Ĵ�С
    //�ڶ�������ǰ���������������������Ϊ������ͬʱK--
    //�����������K������0����ô����ת����ֵ��С��Ԫ�أ���K����
    //���Ĳ������
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // ��һ��
        for (int i = 0; i < A.size(); i++) { // �ڶ���  5��-4��-3��2��-1
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // ������
        int result = 0;
        for (int a : A) result += a;        // ���Ĳ�
        return result;
    }
};
//�º��� ��ӡһά���� vector<string>
struct print002 {
    void operator()(string val) {
        cout << val << " ";
    }
};
void print_vector_str(vector<string> res)
{
    for_each(res.begin(), res.end(), print002());
    cout << endl;
}
//��ӡ��ά����
template<typename T>
void PrintVecofVec2(vector<vector<T>>& res) {
    for (auto& rowV : res) {
        for (auto& el : rowV) {
            cout << el << " ";
        }
        cout << "; ";
    }
    cout << endl;
}
void test()
{
    Solution* obj = new Solution();
    vector<int> g = { 2,-3,-1,5,-4 };

    int res = obj->largestSumAfterKNegations(g,1);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}