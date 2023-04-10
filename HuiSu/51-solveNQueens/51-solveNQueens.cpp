#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//n �ʺ����� �о�������ν� n ���ʺ������ n��n �������ϣ�����ʹ�ʺ�˴�֮�䲻���໥������
//
//����һ������ n ���������в�ͬ�� n �ʺ����� �Ľ��������
//
//ÿһ�ֽⷨ����һ����ͬ�� n �ʺ����� �����ӷ��÷������÷����� 'Q' �� '.' �ֱ�����˻ʺ�Ϳ�λ��
//
//ʾ�� 1��
//
//
//
//���룺n = 4
//����� [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]
//�����㷨 ��Ƕ��n��forѭ��
class Solution {
public:

    //��Ž��  [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    vector<vector<string>> res;
    //���̵Ŀ�Ⱦ���forѭ���ĳ��ȣ��ݹ����Ⱦ������̵ĸ߶�
    //����==��ȣ�����==ѭ�����������ϴ�С
    void back(int n, int raw, vector<string>& chessboard)  // ������ void
    {
        // n Ϊ��������̴�С
        // row �ǵ�ǰ�ݹ鵽���̵ĵڼ�����
        //��ֹ����  ��������ȡ��ݹ鵽�����һ��
        if (raw == n)
        {
            res.push_back(chessboard);
            return;
        }

        //ĳһ�п�ʼѭ����ѭ��ÿһ��
        for (int rol = 0; rol < n; rol++)
        {
            //�ж��Ƿ���Դ�Żʺ�
            if (isVaild(raw, rol, n, chessboard))
            {
                chessboard[raw][rol] = 'Q';
                back(n, raw + 1, chessboard);//�ݹ�һ�㣬����һ��
                chessboard[raw][rol] = '.';
            }
        }

    }

    //��֤�Ƿ��ܷ���
    bool isVaild(int raw, int rol, int n, vector<string>& chessboard)
    {
        //���rol��
        for (int r = 0; r < raw; r++)  //����Q֮���ж�false���ֻ���
        {
            if (chessboard[r][rol] == 'Q')
                return false;
        }
        //���45��  ������������
        for (int i = raw - 1, j = rol - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        //���135��  ������������
        for (int i = raw - 1, j = rol + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;

    }

    vector<vector<string>> solveNQueens(int n) {

        //��ʼ������ 
        // ...
        // ...
        // ...
        //["...","...","..."]
        vector<string> chessboard(n, string(n, '.'));
        back(n, 0, chessboard);
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
//template < typename T>
//void printvector2(vector<vector<T>>& A) {
//    for (vector<vector<T>>::iterator i = A.begin(); i != A.end(); i++) {
//        for (vector<T>::iterator j = i->begin(); j != i->end(); j++) {
//            cout << *j << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
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
    Solution* s = new Solution();
    vector<vector<string>> tickets = { {"JFK","SFO"} ,{"JFK","ATL"} , {"SFO", "ATL"},{"ATL", "JFK"},{"ATL", "SFO"} };
    vector<vector<string>> res = s->solveNQueens(5);
    PrintVecofVec2<string>(res);

}
int main()
{
    test();
    return 0;
}