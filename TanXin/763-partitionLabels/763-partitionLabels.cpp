#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//�ַ��� S ��Сд��ĸ��ɡ�����Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ��ĸ��������һ��Ƭ���С�����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�
//
//ʾ����
//
//���룺S = "ababcbacadefegdehijhklij"
//�����[9, 7, 8] ���ͣ� ���ֽ��Ϊ "ababcbaca", "defegde", "hijhklij"�� ÿ����ĸ��������һ��Ƭ���С� 
//�� "ababcbacadefegde", "hijhklij" �Ļ����Ǵ���ģ���Ϊ���ֵ�Ƭ�������١�

class Solution {
public:
    vector<int> partitionLabels(string s) {

        //��¼���һ����ĸ���ֵ�λ��
        int hash[27] = { 0 }; // 0-26�±� ����a-z
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;//������ĸ��λ��
        }

        vector<int> res;
        //�����ַ�������ʼ����ʼλ�ã����㡢�ж��յ�λ��
        int left = 0;
        int max_hash = 0; // ��Զ�±� 
        for (int i = 0; i < s.size(); i++)
        {
            //��¼���³�����Զ�±� right
            //i������ ��Զ�±� ��ʹ�ָ��
            //�����յ�λ��left
            max_hash = max(max_hash, hash[s[i] - 'a']);// a ����Զ�±�8 
            if (i == max_hash)//�ֲ����ţ��ҵ��׶�����Զ�±꣬�׶���ֹ��������Զ�±�ͬ����ֵ��ͬ
            {
                res.push_back(i - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};

//�º��� ��ӡһά���� vector<string>
template<typename T>
struct print002 {
    void operator()(T val) {
        cout << val << " ";
    }
};
template<typename T>
void print_vector_str(vector<T> res)
{
    for_each(res.begin(), res.end(), print002<T>());
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
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = obj->partitionLabels(s);
    //cout << res << endl;
    print_vector_str<int>(res);

}
int main()
{
    test();
    return 0;
}