#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
// �ڶ�ά�ռ�����������ε����򡣶���ÿ�������ṩ��������ˮƽ�����ϣ�����ֱ���Ŀ�ʼ�ͽ������ꡣ��������ˮƽ�ģ����������겢����Ҫ��
//���ֻҪ֪����ʼ�ͽ����ĺ�������㹻�ˡ���ʼ��������С�ڽ������ꡣ

// һ֧������������ x ��Ӳ�ͬ����ȫ��ֱ������������� x �����һ֧��������һ�������ֱ���Ŀ�ʼ�ͽ�������Ϊ xstart��xend�� ��
//����  xstart �� x �� xend���������ᱻ��������������Ĺ���������û�����ơ� ����һ�������֮�󣬿������޵�ǰ�����������ҵ�ʹ����������ȫ��������������Ĺ�������С������

// ����һ������ points ������ points [i] = [xstart,xend] �������������������������������С��������

// ʾ�� 1��

// ���룺points = [[10,16],[2,8],[1,6],[7,12]]
// �����2
// ���ͣ����ڸ�������x = 6 �����䱬 [2,8],[1,6] ���������Լ� x = 11 �䱬������������
class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);
        int res = 1;  // points ��Ϊ��������Ҫһ֧��
        for (int i = 1; i < points.size(); i++)
        {
            //������ص�����+1�����ص�����С�ұ߽�С����һλ����߽�
            //����ص���������С�ұ߽�,�����£����չ˲����ұ�С������
            if (points[i - 1][1] < points[i][0])
            {
                res++;
            }
            else
            {
                points[i][1] = min(points[i][1], points[i - 1][1]);
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
    vector<int> g = { 5,5,5,10,20 };
    vector<vector<int>> people = { {7,0} ,{4,4},{7,1},{5,0},{6,1},{5,2} };
    int res = obj->findMinArrowShots(people);
    cout << res << endl;
    //PrintVecofVec2(res);

}
int main()
{
    test();
    return 0;
}