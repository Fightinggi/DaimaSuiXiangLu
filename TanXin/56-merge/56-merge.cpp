#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//����һ������ļ��ϣ���ϲ������ص������䡣
//
//ʾ�� 1:
//
//����: intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
//��� : [[1, 6], [8, 10], [15, 18]]
//���� : ����[1, 3] ��[2, 6] �ص�, �����Ǻϲ�Ϊ[1, 6].
using namespace std;
class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //��߽��С��������
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] >= intervals[i][0])  //���ص�����
            {
                //�������ұ߽�
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else //���ص� ������һ���ص�����
            {
                res.push_back(intervals[i]);
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
    vector<int> g = { 1,2 };
    vector<vector<int>> people = { {1,3} ,{2,6},{8,10},{15,18} };
    vector<vector<int>> res = obj->merge(people);
    //cout << res << endl;
    PrintVecofVec2(res);

}
int main()
{
    test();
    return 0;
}