#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//
//每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//示例 1：
//
//
//
//输入：n = 4
//输出： [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]
//回溯算法 ；嵌套n个for循环
class Solution {
public:

    //存放结果  [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    vector<vector<string>> res;
    //棋盘的宽度就是for循环的长度，递归的深度就是棋盘的高度
    //行数==深度，列数==循环次数，集合大小
    void back(int n, int raw, vector<string>& chessboard)  // 多个结果 void
    {
        // n 为输入的棋盘大小
        // row 是当前递归到棋盘的第几行了
        //终止条件  行数、深度、递归到了最后一行
        if (raw == n)
        {
            res.push_back(chessboard);
            return;
        }

        //某一行开始循环，循环每一列
        for (int rol = 0; rol < n; rol++)
        {
            //判断是否可以存放皇后
            if (isVaild(raw, rol, n, chessboard))
            {
                chessboard[raw][rol] = 'Q';
                back(n, raw + 1, chessboard);//递归一层，向下一行
                chessboard[raw][rol] = '.';
            }
        }

    }

    //验证是否能放置
    bool isVaild(int raw, int rol, int n, vector<string>& chessboard)
    {
        //检查rol列
        for (int r = 0; r < raw; r++)  //填了Q之后，判断false，又回溯
        {
            if (chessboard[r][rol] == 'Q')
                return false;
        }
        //检查45度  不能右上左下
        for (int i = raw - 1, j = rol - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        //检查135度  不能左上右下
        for (int i = raw - 1, j = rol + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }
        return true;

    }

    vector<vector<string>> solveNQueens(int n) {

        //初始化棋盘 
        // ...
        // ...
        // ...
        //["...","...","..."]
        vector<string> chessboard(n, string(n, '.'));
        back(n, 0, chessboard);
        return res;
    }
};

//仿函数 打印一维数组 vector<string>
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
//打印二维数组
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
//打印二维数组
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