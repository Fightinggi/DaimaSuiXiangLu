#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//����һ������ļ��ϣ��ҵ���Ҫ�Ƴ��������С������ʹʣ�����以���ص���
//
//ע�� : ������Ϊ������յ����Ǵ���������㡣 ����[1, 2] ��[2, 3] �ı߽��໥���Ӵ�������û���໥�ص���
//
//ʾ�� 1 :
//
//    ���� : [[1, 2], [2, 3], [3, 4], [1, 3]]
//    ��� : 1
//    ���� : �Ƴ�[1, 3] ��ʣ�µ�����û���ص���
class Solution {
public:

    //�����м����ص����䣬������-�ص��������� = ��Ҫ�Ƴ��������С����
    //��֤ �����ص�����ֻ��һ�����䣬����Ķ���Ҫ

    //�ұ߽����� ��С����
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int end = intervals[0][1]; //��¼��һ���ұ߽�  
        for (int i = 1; i < intervals.size(); i++)
        {
            //�ж��Ƿ��ص�,û���ص����ص�����������1,�����趨��С�ұ߽�
            // if(end <= intervals[i][0])
            // {
            //     end = intervals[i][1];  //������С�ұ߽�
            //     count++;//����
            // }
            if (intervals[i - 1][1] <= intervals[i][0])
            {
                count++;
            }
            else
            {
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }
        return intervals.size() - count;

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
    vector<vector<int>> people = { {1,2} ,{2,3},{3,4},{1,3} };
    int res = obj->eraseOverlapIntervals(people);
    cout << res << endl;
    //PrintVecofVec2(res);

}
int main()
{
    test();
    return 0;
}