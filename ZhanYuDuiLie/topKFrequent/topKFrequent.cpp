#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

//优先级队列
class Solution {
public:
    //所以我们要用小顶堆，因为要统计最大前k个元素，
    //只有小顶堆每次将最小的元素弹出，最后小顶堆里积累的才是前k个最大元素。

    class mycomparsion
    {
    public:
        //仿函数
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }

    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        //统计频率
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        //对频率排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparsion> pri_que;

        //扫描 小顶堆 小的从堆顶出队  保留大的
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        {
            pri_que.push(*it);

            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }
        //倒序导出
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = pri_que.top().first;  //取出顶堆的第一个key值 不是频率值
            pri_que.pop();
        }
        return res;
    }
};

struct print001 {
    void operator()(int val) {
        cout << val << " ";
    }
};

void printvector(vector<int> res) {

    for_each(res.begin(), res.end(), print001());
    cout << endl;

}
void test()
{
    vector<int> s = { 1,1,1,2,2,3 };
    Solution so = Solution();

    vector<int> res = so.topKFrequent(s, 2);
    printvector(res);


}

int main()
{
    test();

    //system("pause");
    return 0;
}