#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

//���ȼ�����
class Solution {
public:
    //��������Ҫ��С���ѣ���ΪҪͳ�����ǰk��Ԫ�أ�
    //ֻ��С����ÿ�ν���С��Ԫ�ص��������С��������۵Ĳ���ǰk�����Ԫ�ء�

    class mycomparsion
    {
    public:
        //�º���
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }

    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        //ͳ��Ƶ��
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        //��Ƶ������
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparsion> pri_que;

        //ɨ�� С���� С�ĴӶѶ�����  �������
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        {
            pri_que.push(*it);

            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }
        //���򵼳�
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = pri_que.top().first;  //ȡ�����ѵĵ�һ��keyֵ ����Ƶ��ֵ
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