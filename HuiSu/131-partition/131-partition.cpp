#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//����һ���ַ��� s���� s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��Ĵ���
//
//���� s ���п��ܵķָ����
//
//ʾ�� : ����: "aab" ��� : [["aa", "b"], ["a", "a", "b"]]
//�����㷨 ���õݹ����forѭ��Ƕ�׵�����
//forѭ������������ݹ�������������ݲ��ϵ����������
class Solution {
public:

    //��Ž��
    vector<string> path;
    vector<vector<string>> res;
    //���ݺ���
    void back(const string& s, int start_index)
    {
        //��ֹ����
        if (start_index >= s.size())
        {
            res.push_back(path);
            return;
        }

        //��������
        for (int i = start_index; i < s.size(); i++)
        {
            if (isPalindrome(s, start_index, i))//����ǻ��Ĵ�
            {
                // ��ȡ[startIndex,i]��s�е��Ӵ�
                string str = s.substr(start_index, i - start_index + 1);
                path.push_back(str);
            }
            else
            {
                continue; // ���ǻ��ģ�����
            }
            back(s, i + 1);// Ѱ��i+1Ϊ��ʼλ�õ��Ӵ�
            path.pop_back();
        }

    }

    //�жϻ���
    bool isPalindrome(const string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        if (s.size() == 0)
            return res;
        back(s, 0);
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
    //�º���  ��������ʹ��
   /* for_each(res.begin(), res.end(), print002<T>());
    cout << endl;*/

    //��������
    for_each(res.begin(), res.end(), [](T val) { cout << val << " "; });
    cout << endl;
}
//��ӡ��ά����
//template<typename T>
//void printvector2(vector<vector<T>>& A) {
//    for (vector<vector<T>>::iterator i = A.begin(); i != A.end(); i++) {
//        for (vector<T>::iterator j = i->begin(); j != i->end(); j++) {
//            cout << *j << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
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
    string in = "aab";
    vector<vector<string>> res = s->partition(in);
    PrintVecofVec1<string>(res);

}
int main()
{
    test();
    return 0;
}