#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//��ʦ��������Ƿַ��ǹ����� N ������վ����һ��ֱ�ߣ���ʦ�����ÿ�����ӵı��֣�Ԥ�ȸ��������֡�
//
//����Ҫ��������Ҫ�󣬰�����ʦ����Щ���ӷַ��ǹ���
//
//ÿ���������ٷ��䵽 1 ���ǹ���
//���ڵĺ����У����ָߵĺ��ӱ����ø�����ǹ���
//��ô������������ʦ������Ҫ׼�����ٿ��ǹ��أ�
//
//ʾ�� 1:
//
//����: [1, 0, 2]
//��� : 5
//���� : ����Էֱ�����������ӷַ� 2��1��2 ���ǹ���
using namespace std;
class Solution {
public:
    //�����Ŀһ����Ҫȷ��һ��֮����ȷ����һ�ߣ�����Ƚ�ÿһ�����ӵ���ߣ�Ȼ���ٱȽ��ұߣ��������һ����һ����˴�ʧ�ˡ�
    int candy(vector<int>& ratings) {

        vector<int> candyVec(ratings.size(), 1);

        //���ң��Ҵ�����candy+1��С��candy����
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                candyVec[i] = candyVec[i - 1] + 1;  //����һλ����һλ
        }
        //�ҵ���������ң�candy+1��С��candy����
        for (int i = ratings.size() - 2; i > 0; i--)
        {
            if (ratings[i] > ratings[i + 1]) //ȫ�����ţ����ڵĺ����У����ָߵ��Һ��ӻ�ñ���ߺ��Ӹ�����ǹ�
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
        }
        //ͳ�ƽ��
        int res = 0;
        for (int can : candyVec) res += can;
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
    vector<int> g = { 1,0,2 };
    vector<int> s = { 3,4,5,1,2 };

    int res = obj->candy(g);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}