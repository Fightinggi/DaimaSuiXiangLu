#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>

using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        //123 θ�� g
        //11 ���� s
        int index = s.size() - 1;
        int res = 0;
        for (int i = g.size() - 1; i >= 0; i--)//�ȱ���θ�ڣ��ٱ������ɿ���û�з��ϵģ������ܶ��ʹ�ñ���
        {
            if (index >= 0 && s[index] >= g[i])
            {
                index--;//������ƥ�䵽������һλ
                res++;//��¼ƥ����
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
    vector<int> s = { 1,2,3 };
    int res = obj->findContentChildren(g, s);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}