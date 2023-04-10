#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//给定一个机票的字符串二维数组[from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。
//
//提示：
//
//如果存在多种有效的行程，请你按字符自然排序返回最小的行程组合。例如，行程["JFK", "LGA"] 与["JFK", "LGB"] 相比就更小，排序更靠前
//所有的机场都用三个大写字母表示（机场代码）。
//假定所有机票至少存在一种合理的行程。
//所有的机票必须都用一次 且 只能用一次。
//示例 1：
//
//输入： [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//输出：["JFK", "MUC", "LHR", "SFO", "SJC"]
//回溯算法 ；嵌套n个for循环
class Solution {
public:


    //存放结果
    vector<string> res;
    //存放出发-达到的映射关系, 同used作用，记录用过的机票
    //unordered_map<出发机场, map<到达机场, 航班次数>> targets
    map<string, map<string, int>> targets;

    //回溯函数
    bool back(vector<string>& res, int ticketNum)  // 唯一解  bool
    {
        //终止条件  机票数==行程数  每递归一次，树的深度加一，就会判断一次，就加一，
        if (res.size() == ticketNum + 1)
        {
            return true;
        }
        //单层搜索  搜索从行程的最后一行个地方出发 到 其他含有车票的机场有哪些，有的push_back
        // 出发机场JFK能到达哪些打到机场，去过的int值=0
        for (pair<const string, int>& tar : targets[res[res.size() - 1]])
        {
            if (tar.second > 0)  //说明有去目的机场的机票
            {
                tar.second--;  //去过了减一。
                res.push_back(tar.first);
                if (back(res, ticketNum)) return true;
                res.pop_back();
                tar.second++;//回溯，这个行程不行，撤回，机票还能用
            }

        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        // tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
        // targets = {
        //             ["JFK",[("SFO",1);("ATL",1)]];
        //             ["SFO",[("ATL",1)]];
        //             ["ATL",[("JFK",1);("SFO",1)]]
        //            }
        //初始化 targets 记录映射关系
        for (const vector<string>& tic : tickets)
        {
            targets[tic[0]][tic[1]]++;
        }
        res.push_back("JFK");
        back(res, tickets.size());
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
    vector<vector<string>> tickets = { {"JFK","SFO"} ,{"JFK","ATL"} , {"SFO", "ATL"},{"ATL", "JFK"},{"ATL", "SFO"} };
    vector<string> res = s->findItinerary(tickets);
    print_vector_str(res);
   
}
int main()
{
    test();
    return 0;
}