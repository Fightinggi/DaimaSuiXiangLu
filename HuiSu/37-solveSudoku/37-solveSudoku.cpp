#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//��дһ������ͨ�����ո�������������⡣
//
//һ�������Ľⷨ����ѭ���¹��� ���� 1 - 9 ��ÿһ��ֻ�ܳ���һ�Ρ� ���� 1 - 9 ��ÿһ��ֻ�ܳ���һ�Ρ� ���� 1 - 9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ� �հ׸��� '.' ��ʾ��
//�����㷨 ��Ƕ��n��forѭ��
class Solution {
public:

    //�н�ͷ���  ����Ψһ��
    bool back(vector<vector<char>>& board)
    {

        //һ��һ�������������ݹ鲻����һ���ˣ���ͬ�еĺ�һλ������˵ÿ���ո���9�п��ܣ��ӵ�һ���ո�ʼ��1-9���ԣ���
        //��N�ʺ�ͬ������һ��ֻ��һ��Q�������Ĳ�����
        //��������λ��
        for (int raw = 0; raw < board.size(); raw++)
        {
            for (int rol = 0; rol < board[0].size(); rol++)
            {
                //��ʼ��[raw, rol]λ������
                //�ж��Ƿ�Ϊ�յ�
                if (board[raw][rol] == '.')
                {
                    //����1-9���п��ܵ���
                    for (char k = '1'; k <= '9'; k++)
                    {
                        //1-9�з������������ֲ��ܼ�����
                        if (isVaild(raw, rol, k, board))
                        {
                            board[raw][rol] = k;  //����k
                            if (back(board)) return true;
                            board[raw][rol] = '.';//�����ϵĻ��� ����ؿո� ����k
                        }
                    }
                    return false;//�������ֳ��Ժ󶼲��У��ͷ���false���з��ϵ���for���Ѿ���������true
                }
            }
        }
        return true;/// ������û�з���false��˵���ҵ��˺�������λ����

    }


    bool isVaild(int raw, int rol, char val, vector<vector<char>>& board)
    {
        //����raw����û���ظ���
        for (int i = 0; i < 9; i++)
        {
            if (board[raw][i] == val)
                return false;
        }
        //����rol��
        for (int j = 0; j < 9; j++)
        {
            if (board[j][rol] == val)
                return false;
        }
        //�Ź���
        //����raw��rol��ȷ������ 
        //[0,0] [0,3] [0,6]
        //[3,0] [3,3] [3,6]
        //[6,0] [6,3] [6,6]
        int start_raw = (raw / 3) * 3;
        int start_rol = (rol / 3) * 3;
        for (int i = start_raw; i < start_raw + 3; i++)
        {
            for (int j = start_rol; j < start_rol + 3; j++)
            {
                if (board[i][j] == val)
                    return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        back(board);

    }
};


//��ӡ��ά����
template<typename T>
void PrintVecofVec2(vector<vector<T>>& res) {
    for (auto& rowV : res) {
        for (auto& el : rowV) {
            cout << el << " ";
        }
        cout << ",\n";
    }
    cout << endl;
}
void test()
{
    Solution* s = new Solution();
    vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'} };

    s->solveSudoku(board);
    PrintVecofVec2<char>(board);


}
int main()
{
    test();
    return 0;
}