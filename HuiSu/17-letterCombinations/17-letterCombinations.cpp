#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

//�����㷨 ���õݹ����forѭ��Ƕ�׵�����
//forѭ������������ݹ�������������ݲ��ϵ����������
class Solution {
public:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

    vector<string> res;
    string s;
    void back(const string& digits, int index)
    {
        if (index == digits.size())
        {
            res.push_back(s);
            return;
        }

        int digit = digits[index] - '0';//�õ�string��indexλ�õ�����
        string letters = letterMap[digit]; //�õ�digits��index�µ����ֶ�Ӧ��������ĸ
        for (int i = 0; i < letters.size(); i++)
        {
            s.push_back(letters[i]);
            back(digits, index + 1);
            s.pop_back();
            //���صĻ���  �ǰ���һ��Ҫ�ݹ������ֱ�ӷŽ��ݹ麯����ִ���жϣ�
            //back(digits, index + 1, s + letters[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        res.clear();
        if (digits.size() == 0)
            return res;
        back(digits, 0);
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
void printvector2(vector<vector<int>>& A) {
    for (vector<vector<int>>::iterator i = A.begin(); i != A.end(); i++) {
        for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void test()
{
    Solution* s = new Solution();
    string in = "23";
    vector<string> res = s->letterCombinations(in);
    print_vector_str(res);
}
int main()
{
    test();
    return 0;
}