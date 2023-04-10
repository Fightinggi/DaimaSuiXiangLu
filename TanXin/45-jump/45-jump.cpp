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
//���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�
//
//ʾ�� :
//
//����: [2, 3, 1, 1, 4]
//��� : 2
//���� : �������һ��λ�õ���С��Ծ���� 2�����±�Ϊ 0 �����±�Ϊ 1 ��λ�ã��� 1 ����Ȼ���� 3 ��������������һ��λ�á�
using namespace std;
class Solution {
public:
    /*�������������ʱ��Ҫ�Ӹ��Ƿ�Χ������������ô�������Ƿ�Χ��һ���ǿ��������ģ�����С�Ĳ������Ӹ��Ƿ�Χ�����Ƿ�Χһ���������յ㣬�õ��ľ�����С������

    ������Ҫͳ���������Ƿ�Χ����ǰ��һ������󸲸Ǻ���һ����󸲸�*/
    //��һ���ĸ��Ƿ�Χ�����յ�ʱ��ֱ��һ����λ
    //������ÿ���߶�Զ��ֻ���㣬һ��һ���ߵ���ǰ������Զ�����±�ʱ��û�ߵ��յ�ʱ�����ڸ��Ƿ�Χ�ҵ������±�����ǰ��
    int Jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int curDistance = 0;    // ��ǰ������Զ�����±�
        int ans = 0;            // ��¼�ߵ������
        int nextDistance = 0;   // ��һ��������Զ�����±�
        for (int i = 0; i <= nextDistance; i++) {
            nextDistance = max(nums[i] + i, nextDistance);  // ������һ��������Զ�����±�
            if (i == curDistance)  // ������ǰ������Զ�����±�
            {                        
                if (curDistance < nums.size() - 1) 
                {       // �����ǰ������Զ�����±겻���յ�
                    ans++;                                  // ��Ҫ����һ��
                    curDistance = nextDistance;             // ���µ�ǰ������Զ�����±꣨�൱�ڼ����ˣ�
                    if (nextDistance >= nums.size() - 1) break; // ��һ���ĸ��Ƿ�Χ�Ѿ����Դﵽ�յ㣬����ѭ��
                }
                else break;                               // ��ǰ������Զ�ൽ�Ｏ���յ㣬������ans++�����ˣ�ֱ�ӽ���
            }
        }
        return ans;
    }

    //========================������ô�࣬�Ͱ������� II/===========================
    int jump(vector<int>& nums)
    {
        int ans = 0;
        int end = 0;
        int maxPos = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxPos = max(nums[i] + i, maxPos);
            if (i == end)
            {
                end = maxPos;
                ans++;
            }
        }
        return ans;
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

    int res = obj->Jump(g);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}