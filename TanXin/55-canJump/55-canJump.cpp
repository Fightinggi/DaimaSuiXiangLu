#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//����һ���Ǹ��������飬�����λ������ĵ�һ��λ�á�
//
//�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
//
//�ж����Ƿ��ܹ��������һ��λ�á�
//
//ʾ�� 1:
//
//����: [2, 3, 1, 1, 4]
//��� : true
//���� : ���ǿ������� 1 ������λ�� 0 ���� λ�� 1, Ȼ���ٴ�λ�� 1 �� 3 ���������һ��λ�á�
using namespace std;
class Solution {
public:
    // ̰���㷨�ֲ����Ž⣺ÿ��ȡ�����Ծ������ȡ��󸲸Ƿ�Χ�����������Ž⣺���õ�������󸲸Ƿ�Χ�����Ƿ��ܵ��յ㡣
    // ������������������Ŀ����--�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�ֻҪ��󳤶��ܸ����յ��������.
    

    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true; // ֻ��һ��Ԫ�أ������ܴﵽ
        int count = 0; //��¼��iλ�ø��Ƿ�Χ
        int i = 0;
        for (; i <= count; i++)
        {
            count = max(count, i + nums[i]);  //i+nums[i] ��iλ���ܸ��ǵ���λ��
            if (count >= nums.size() - 1) return true;//���Ƿ�Χ�ܸ��ǵ����һ��Ԫ��λ�þͷ���true 
        }
        return false;
    }
};
// 1�����ĳһ����Ϊ ������ �ĸ��ӿ�����Ծ�ľ����� 3����ô��ʾ���� 3 �����Ӷ�������Ϊ ������
// 2�����Զ�ÿһ������Ϊ ������ �ĸ��Ӷ�������һ�Σ��� ��������Զ�ľ��� ���ϸ���
// 3���������һֱ������󣬾ͳɹ���
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;//��¼�ܵ�����Զ�±�
        for (int i = 0; i < nums.size(); i++) {
            if (k < i) return false;//�ж�ά�����ܵ���Զ�±�  �ܷ����i
            k = max(k, i + nums[i]);//ά��һ���ܵ���Զ�±����  ���жϵĻ�  max���������һ����
        }
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
    vector<int> g = { 2,3,1,1,4 };

    bool res = obj->canJump(g);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}