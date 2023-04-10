#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//�����д���˳���һȺ��վ��һ�����У����� people ��ʾ������һЩ�˵����ԣ���һ����˳�򣩡�ÿ�� people[i] = [hi, ki] ��ʾ�� i ���˵����Ϊ hi ��ǰ�� ���� �� ki ����ߴ��ڻ���� hi ���ˡ�
//
//�������¹��첢������������ people ����ʾ�Ķ��С����صĶ���Ӧ�ø�ʽ��Ϊ���� queue ������ queue[j] = [hj, kj] �Ƕ����е� j ���˵����ԣ�queue[0] �����ڶ���ǰ����ˣ���
//
//ʾ�� 1��
//
//���룺people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
//����� [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
//���ͣ�
//���Ϊ 0 �������Ϊ 5 ��û����߸��߻�����ͬ����������ǰ�档
//���Ϊ 1 �������Ϊ 7 ��û����߸��߻�����ͬ����������ǰ�档
//���Ϊ 2 �������Ϊ 5 ���� 2 ����߸��߻�����ͬ����������ǰ�棬�����Ϊ 0 �� 1 ���ˡ�
//���Ϊ 3 �������Ϊ 6 ���� 1 ����߸��߻�����ͬ����������ǰ�棬�����Ϊ 1 ���ˡ�
//���Ϊ 4 �������Ϊ 4 ���� 4 ����߸��߻�����ͬ����������ǰ�棬�����Ϊ 0��1��2��3 ���ˡ�
//���Ϊ 5 �������Ϊ 7 ���� 1 ����߸��߻�����ͬ����������ǰ�棬�����Ϊ 1 ���ˡ�
//��� [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]] �����¹����Ķ��С�
using namespace std;
//��135.�ַ��ǹ�(opens new window)�Ҿ�ǿ����һ�Σ���������ά��Ȩ���ʱ��һ��Ҫ��ȷ��һ��ά�ȣ���ȷ����һ��ά�ȡ�
//
//�������ά��һ����һ����˴�ʧ�ˡ�
class Solution {
public:
    //people[i] = [hi, ki]
    // h��ͬ k��С����
    // ���h�Ӵ�С����
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] == b[0])  return a[1] < b[1];
        return a[0] > b[0];
    }
    // �ֲ����ţ����Ȱ���߸ߵ�people��k�����롣������������people�����������
    // ȫ�����ţ������������������������������Ŀ��������
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (auto p : people)
        {
            //����С����ǰ���룬����Ӱ��ԭ���������������
            if (p[1] < res.size())  //���p[1]С��res���飬˵����Ҫ���м���룬�����λ����k����
                res.insert(res.begin() + p[1], p);  //��p[1]��λ�ò���Ԫ��p
            else
                res.push_back(p);

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
    vector<vector<int>> res = obj->reconstructQueue(people);
    //cout << res << endl;
    PrintVecofVec2(res);

}
int main()
{
    test();
    return 0;
}