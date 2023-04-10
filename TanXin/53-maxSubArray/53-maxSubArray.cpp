#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
//
//ʾ�� :
//
//����: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//��� : 6
//���� : ����������[4, -1, 2, 1] �ĺ����Ϊ 6
using namespace std;
class Solution {
public:
    //-2,1,-3,4,-1,2,1,-5,4
    //������������  �Ǿֲ����ŵ�
    int maxSubArray(vector<int>& nums) {

        int res = INT32_MIN;
        int count = 0;//������
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];  //����������
            if (count > res)   res = count;  // ȡ�����ۼƵ����ֵ���൱�ڲ���ȷ�����������ֹλ�ã�
            if (count <= 0)  count = 0; //���¿�ʼ���������ͣ���Ϊ�����Ժ������ֻ�м�С�����á�
                
        }

        return res;
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
    vector<int> g = { -2,1,-3,4,-1,2,1,-5,4 };

    int res = obj->maxSubArray(g);
    cout << res <<  endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}