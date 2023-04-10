#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
//在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
//
//顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//
//每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
//
//注意，一开始你手头没有任何零钱。
//
//如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
//
//示例 1：
//
//输入：[5, 5, 5, 10, 20]
//输出：true
//解释：
//前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
//第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
//第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
//由于所有客户都得到了正确的找零，所以我们输出 true。
using namespace std;
class Solution {
public:
    // 情况一：账单是5，直接收下。
    // 情况二：账单是10，消耗一个5，增加一个10
    // 情况三：账单是20，优先消耗一个10和一个5，如果不够，再消耗三个5
    // 因为美元10只能给账单20找零，而美元5可以给账单10和账单20找零，美元5更万能！
    // 所以局部最优：遇到账单20，优先消耗美元10，完成本次找零。全局最优：完成全部账单的找零。
    bool lemonadeChange(vector<int>& bills) {
        //数组记录 5、10、20还有几张
        vector<int> vec(2, 0);
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
                vec[0] += 1;

            if (bills[i] == 10) {
                vec[0] -= 1; if (vec[0] < 0) return false;
                vec[1] += 1;
            }
            if (bills[i] == 20) {

                if (vec[1] > 0 && vec[0] > 0) {
                    vec[1] -= 1; if (vec[1] < 0) return false;
                    vec[0] -= 1; if (vec[0] < 0) return false;
                }
                else {
                    vec[0] -= 3; if (vec[0] < 0) return false;
                }
            }
        }
        // for(int v:vec) {
        //     if(v<0) return false;
        // }
        return true;
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
    vector<int> g = { 5,5,5,10,20 };

    bool res = obj->lemonadeChange(g);
    cout << res << endl;
    //print_vector_str(res);

}
int main()
{
    test();
    return 0;
}