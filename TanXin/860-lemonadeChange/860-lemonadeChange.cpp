#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//������ˮ̯�ϣ�ÿһ������ˮ���ۼ�Ϊ 5 ��Ԫ��
//
//�˿��Ŷӹ�����Ĳ�Ʒ�������˵� bills ֧����˳��һ�ι���һ����
//
//ÿλ�˿�ֻ��һ������ˮ��Ȼ�����㸶 5 ��Ԫ��10 ��Ԫ�� 20 ��Ԫ��������ÿ���˿���ȷ���㣬Ҳ����˵��������ÿλ�˿�����֧�� 5 ��Ԫ��
//
//ע�⣬һ��ʼ����ͷû���κ���Ǯ��
//
//������ܸ�ÿλ�˿���ȷ���㣬���� true �����򷵻� false ��
//
//ʾ�� 1��
//
//���룺[5, 5, 5, 10, 20]
//�����true
//���ͣ�
//ǰ 3 λ�˿�������ǰ�˳����ȡ 3 �� 5 ��Ԫ�ĳ�Ʊ��
//�� 4 λ�˿����������ȡһ�� 10 ��Ԫ�ĳ�Ʊ�������� 5 ��Ԫ��
//�� 5 λ�˿���������һ�һ�� 10 ��Ԫ�ĳ�Ʊ��һ�� 5 ��Ԫ�ĳ�Ʊ��
//�������пͻ����õ�����ȷ�����㣬����������� true��
using namespace std;
class Solution {
public:
    // ���һ���˵���5��ֱ�����¡�
    // ��������˵���10������һ��5������һ��10
    // ��������˵���20����������һ��10��һ��5���������������������5
    // ��Ϊ��Ԫ10ֻ�ܸ��˵�20���㣬����Ԫ5���Ը��˵�10���˵�20���㣬��Ԫ5�����ܣ�
    // ���Ծֲ����ţ������˵�20������������Ԫ10����ɱ������㡣ȫ�����ţ����ȫ���˵������㡣
    bool lemonadeChange(vector<int>& bills) {
        //�����¼ 5��10��20���м���
        vector<int> vec(2, 0);
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                vec[0] += 1;

            if (bills[i] == 10) {
                vec[0] -= 1; if (vec[0] < 0) return false;
                vec[1] += 1;
            }
            if (bills[i] == 20) {

                if (vec[1] > 0 && vec[0] > 0) {
                    vec[1] -= 1; if (vec[1] < 0) return false;
                    vec[0] -= 1; if (vec[0] < 0) return false;
                }
                else {
                    vec[0] -= 3; if (vec[0] < 0) return false;
                }
            }
        }
        // for(int v:vec) {
        //     if(v<0) return false;
        // }
        return true;
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
    vector<int> g = { 5,5,5,10,20 };

    bool res = obj->lemonadeChange(g);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}