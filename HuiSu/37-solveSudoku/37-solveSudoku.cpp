#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//编写一个程序，通过填充空格来解决数独问题。
//
//一个数独的解法需遵循如下规则： 数字 1 - 9 在每一行只能出现一次。 数字 1 - 9 在每一列只能出现一次。 数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 空白格用 '.' 表示。
//回溯算法 ；嵌套n个for循环
class Solution {
public:

    //有解就返回  且是唯一解
    bool back(vector<vector<char>>& board)
    {

        //一个一个遍历数独，递归不是下一行了，是同行的后一位，可以说每个空格都有9中可能，从第一个空格开始从1-9尝试，。
        //与N皇后不同，它是一行只有一个Q，其他的不处理
        //遍历数独位置
        for (int raw = 0; raw < board.size(); raw++)
        {
            for (int rol = 0; rol < board[0].size(); rol++)
            {
                //开始在[raw, rol]位置填数
                //判断是否为空的
                if (board[raw][rol] == '.')
                {
                    //尝试1-9所有可能的数
                    for (char k = '1'; k <= '9'; k++)
                    {
                        //1-9中符合条件的数字才能继续填
                        if (isVaild(raw, rol, k, board))
                        {
                            board[raw][rol] = k;  //放置k
                            if (back(board)) return true;
                            board[raw][rol] = '.';//不符合的回溯 并填回空格， 撤销k
                        }
                    }
                    return false;//所有数字尝试后都不行，就返回false；有符合的在for中已经处理并返回true
                }
            }
        }
        return true;/// 遍历完没有返回false，说明找到了合适棋盘位置了

    }


    bool isVaild(int raw, int rol, char val, vector<vector<char>>& board)
    {
        //搜索raw行有没有重复的
        for (int i = 0; i < 9; i++)
        {
            if (board[raw][i] == val)
                return false;
        }
        //搜索rol列
        for (int j = 0; j < 9; j++)
        {
            if (board[j][rol] == val)
                return false;
        }
        //九宫格
        //根据raw和rol，确定区域 
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


//打印二维数组
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