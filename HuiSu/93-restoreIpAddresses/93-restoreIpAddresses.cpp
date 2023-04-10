#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ��
//
//��Ч�� IP ��ַ �������ĸ�������ÿ������λ�� 0 �� 255 ֮����ɣ��Ҳ��ܺ���ǰ�� 0��������֮���� '.' �ָ���
//
//���磺"0.1.2.201" �� "192.168.1.1" �� ��Ч�� IP ��ַ������ "0.011.255.245"��"192.168.1.312" �� "192.168@1.1" �� ��Ч�� IP ��ַ��
//�����㷨 ���õݹ����forѭ��Ƕ�׵�����
//forѭ������������ݹ�������������ݲ��ϵ����������
class Solution {
private:
    //  startIndex��ʾ���/�ݹ����� ���Կ�������  i��ʾ���/ѭ���Ĵ��������Կ�������
    vector<string> result;// ��¼���
    // startIndex: ��������ʼλ�ã�pointNum:��Ӷ��������
    void backtracking(string& s, int startIndex, int pointNum) {
        //�ʼ��"2.5.5.25511135"����ַ����ĵ��Ķβ��Ϸ���return��,Ȼ������"2.5.52.5511135"�������ȵ�
        if (pointNum == 3) { // ��������Ϊ3ʱ���ָ�����  ��pointNum==3 Ҳ���������
            // �жϵ��Ķ����ַ����Ƿ�Ϸ�������Ϸ��ͷŽ�result��
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        //�����㷨==�����㷨 ���н����һһ�ж���
        //���ݵĹ��� ���ǰѲ��Ϸ��Ļ��ߺϷ��Ľ���������ˣ�
        //�Ϸ��Ĵ�������������Ȼ���ټ����ݹ飬���Ϸ���ֱ�ӻ��ݵ���һѭ���ٴ������ж��Ƿ�Ϸ�
        for (int i = startIndex; i < s.size(); i++) {
            // [startIndex, i]  ��ʾ���ΪstartIndex,ѭ������i��ֵ���������i��ʼֵ��������ȵĸı䡣
            if (isValid(s, startIndex, i)) 
            {   // �ж� [startIndex,i] ���������Ӵ��Ƿ�Ϸ�
                s.insert(s.begin() + i + 1, '.');  // ��i�ĺ������һ������
                pointNum++;
                backtracking(s, i + 2, pointNum);   // ���붺��֮����һ���Ӵ�����ʼλ��Ϊi+2
                pointNum--;                         // ����
                s.erase(s.begin() + i + 1);         // ����ɾ������
            }
            else break; // ���Ϸ���ֱ�ӽ�������ѭ��
        }
    }
    // �ж��ַ���s������ֱ�����[start, end]����ɵ������Ƿ�Ϸ�
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0��ͷ�����ֲ��Ϸ�
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // �����������ַ����Ϸ�
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // �������255�˲��Ϸ�
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result; // ���Ǽ�֦��
        backtracking(s, 0, 0);
        return result;
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
    //�º���  ��������ʹ��
   /* for_each(res.begin(), res.end(), print002<T>());
    cout << endl;*/

    //��������
    for_each(res.begin(), res.end(), [](T val) { cout << val << ";" ;});
    cout << endl;
}
//��ӡ��ά����
template<typename T>
void PrintVecofVec1(vector<vector<T>>& res) {
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
    Solution* s = new Solution();
    string in = "25525511135";
    vector<string> res = s->restoreIpAddresses(in);
    print_vector_str<string>(res);
    //PrintVecofVec1<string>(res);

}
int main()
{
    test();
    return 0;
}