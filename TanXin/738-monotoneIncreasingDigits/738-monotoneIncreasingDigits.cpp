#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//����һ���Ǹ����� N���ҳ�С�ڻ���� N ������������ͬʱ���������Ҫ���������λ���ϵ������ǵ���������
//
//�����ҽ���ÿ������λ���ϵ����� x �� y ���� x <= y ʱ�����ǳ���������ǵ��������ġ���
//
//ʾ�� 1:
//
//����: N = 10
//��� : 9
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        string strNum = to_string(n);
        // flag������Ǹ�ֵ9�����￪ʼ
        // ����Ϊ���Ĭ��ֵ��Ϊ�˷�ֹ�ڶ���forѭ����flagû�б���ֵ�������ִ��
        int flag = strNum.size();

        for (int i = strNum.size() - 1; i > 0; i--)
        {
            if (strNum[i - 1] > strNum[i])
            {
                strNum[i - 1]--;
                flag = i;
            }
        }
        for (int i = flag; i < strNum.size(); i++)
        {
            strNum[i] = '9';
        }
        return stoi(strNum);
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
    vector<int> g = { 1,2 };
    vector<int> s = { 1,2,3 };
    int res = obj->monotoneIncreasingDigits(1234);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}