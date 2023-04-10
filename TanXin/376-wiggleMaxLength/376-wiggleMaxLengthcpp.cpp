#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//�����������֮��Ĳ��ϸ���������͸���֮�佻�棬���������г�Ϊ�ڶ����С���һ���������ڵĻ���������������������������Ԫ�ص�����Ҳ�ǰڶ����С�
//
//���磬[1, 7, 4, 9, 2, 5] ��һ���ڶ����У���Ϊ��ֵ(6, -3, 5, -7, 3) ������������ֵġ�
//�෴, [1, 4, 7, 2, 5] ��[1, 7, 4, 5, 5] ���ǰڶ����У���һ����������Ϊ����ǰ������ֵ�����������ڶ�����������Ϊ�������һ����ֵΪ�㡣
using namespace std;
class Solution {
public:
    // = ���һ�����м���ƽ��
    //���ֵnums[i]-nums[i-1] >= 0  && nums[i+1] - nums[i] < 0
    //��Сֵnums[i]-nums[i-1] <= 0  && nums[i+1] - nums[i] > 0
    //��ֻ����������ʱ������ǰ���һλ��nums[0]��ͬ���� {1��1��2}

    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int pre = 0; // ��¼ǰһ������ֻ�иı䷽���ʱ�򣬲Ŷ�pre����
        int cur = 0; // ��¼��һ������
        int res = 1; // ��¼��ֵ����������Ĭ���������ұ���һ����ֵ
        for (int i = 0; i < nums.size() - 1; i++)
        {
            cur = nums[i + 1] - nums[i];
            if ((cur < 0 && pre >= 0) || (cur > 0 && pre <= 0))
            {
                res++;
                pre = cur;// ע�����ֻ�ڰڶ��仯��ʱ�����prediff 
            }
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
    vector<int> g = { 1,17,5,10,13,15,10,5,16,8 };

    int res = obj->wiggleMaxLength(g);
    cout << res <<  endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}