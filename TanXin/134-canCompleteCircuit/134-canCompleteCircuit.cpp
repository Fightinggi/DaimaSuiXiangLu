#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//��һ����·���� N ������վ�����е� i ������վ������ gas[i] ����
//
//����һ�������������޵ĵ��������ӵ� i ������վ������ i + 1 ������վ��Ҫ�������� cost[i] ����������е�һ������վ��������ʼʱ����Ϊ�ա�
//
//���������ƻ�·��ʻһ�ܣ��򷵻س���ʱ����վ�ı�ţ����򷵻� - 1��
//ʾ�� 1: ����:
//
//gas = [1, 2, 3, 4, 5]
//cost = [3, 4, 5, 1, 2]
//��� : 3 ���� :
//
//    �� 3 �ż���վ(����Ϊ 3 ��)�������ɻ�� 4 �����͡���ʱ������ = 0 + 4 = 4 ������
//    ���� 4 �ż���վ����ʱ������ 4 - 1 + 5 = 8 ������
//    ���� 0 �ż���վ����ʱ������ 8 - 2 + 1 = 7 ������
//    ���� 1 �ż���վ����ʱ������ 7 - 3 + 2 = 6 ������
//    ���� 2 �ż���վ����ʱ������ 6 - 4 + 3 = 5 ������
//    ���� 3 �ż���վ������Ҫ���� 5 �����ͣ������㹻�㷵�ص� 3 �ż���վ��
//    ��ˣ�3 ��Ϊ��ʼ������
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //������⣬ģ���ÿ������վ��һȦ�ù���
        //int index = (index+1)%gas.size();  index��[0��size()] ���뼼��
        // for(int i=0; i < gas.size(); i++)
        // {
        //     int rest = gas[i] - cost[i];
        //     int index = (i+1)%gas.size();//������  5%4 = 1
        //     while(rest>0 && index != i)
        //     {
        //         rest += gas[index] - cost[index];
        //         int index = (index+1)%gas.size();
        //     }
        //     if(rest>=0 && index==i) return i;//��һȦ������
        // }
        // return -1;

        int CurSum = 0;
        int TotalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            TotalSum += gas[i] - cost[i];
            CurSum += gas[i] - cost[i];
            if (CurSum < 0) // ��ǰ�ۼ�rest[i]�� curSumһ��С��0
            {
                CurSum = 0;   // curSum��0��ʼ
                start = i + 1;// ��ʼλ�ø���Ϊi+1
            }
        }
        if (TotalSum < 0) return -1;
        return start;

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
    vector<int> g = { 1,2,3,4,5 };
    vector<int> s = { 3,4,5,1,2 };

    int res = obj->canCompleteCircuit(g,s);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}