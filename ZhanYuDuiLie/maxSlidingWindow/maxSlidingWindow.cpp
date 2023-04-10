#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



//单调队列 维护最大值 每次队列进入元素val  连续pop_back出比val小的元素
//维护最大值  如果最大值是滑动窗口往前移动时（下一次push前） 需要pop的元素 先pop  再push  push前先比较大小
//维护最大值的目的是 deque的front永远是队列中最大的  其他位置不考虑

class Solution {
private:
    class MyQueue { //单调队列（从大到小）  
    public:
        deque<int> que; // 使用deque来实现单调队列  //deque  两端都可以进行pop和push操作
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();//向前移动一位
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
            que.push(nums[i]);   // 结果 3 -1
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            // 滑动窗口移除最前面元素  如果没真正执行pop操作则说明再上一次push操作的时候已经pop较小的元素了
            //如果真正执行pop操作，说明pop的值是滑动窗口需要的值也是最大的值 且在front位置。
            que.push(nums[i]); // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
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
    vector<int> s = { 1,3,-1,-3,5,3,6,7 };
    Solution so = Solution();

    vector<int> res = so.maxSlidingWindow(s,3);
    printvector(res);


}

int main()
{
    test();

    //system("pause");
    return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<map>
//using namespace std;
////键值不能重复
//// 
////3.8.2.1 map构造函数
////map<T1, T2> mapTT;//map默认构造函数: 
////map(const map& mp);//拷贝构造函数
////
////
////3.8.2.2 map赋值操作
////map & operator=(const map & mp);//重载等号操作符
////swap(mp);//交换两个集合容器
////
////3.8.2.3 map大小操作
////size();//返回容器中元素的数目
////empty();//判断容器是否为空
////3.8.2.4 map插入数据元素操作
////map.insert(...); //往容器插入元素，返回pair<iterator,bool>
////map<int, string> mapStu;
////// 第一种 通过pair的方式插入对象
////mapStu.insert(pair<int, string>(3, "小张"));
////// 第二种 通过pair的方式插入对象
////mapStu.inset(make_pair(-1, "校长"));
////// 第三种 通过value_type的方式插入对象
////mapStu.insert(map<int, string>::value_type(1, "小李"));
////// 第四种 通过数组的方式插入值
////mapStu[3] = "小刘";
////mapStu[5] = "小王";
////3.8.2.5 map删除操作
////clear();//删除所有元素
////erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
////erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
////erase(keyElem);//删除容器中key为keyElem的对组。
////3.8.2.6 map查找操作
////find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
////count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
////lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
////upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。	
////equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
//
////改变规则
//struct compare
//{
//    bool operator()(int k1, int k2) const
//    {
//        return k1 < k2;
//    }
//};
//template<class T>
//void print(T& m)
//{
//    for (map< int, string, compare >::iterator it = m.begin(); it != m.end(); it++)
//    {
//        cout << " key:" << (*it).first << " value:" << (*it).second << endl;
//    }
//}
//
//void test02() {
//
//    map<int, string, compare> mapStu;
//    // 第一种 通过pair的方式插入对象
//    mapStu.insert(pair<int, string>(3, "小张"));
//    // 第二种 通过pair的方式插入对象
//    mapStu.insert(make_pair(-1, "校长"));
//    // 第三种 通过value_type的方式插入对象
//    mapStu.insert(map<int, string>::value_type(1, "小李"));
//    // 第四种 通过数组的方式插入值
//    mapStu[3] = "小刘";
//
//    print<map<int, string, compare>>(mapStu); //print(mapStu);
//
//    //[]插入时 没有实值 但有键值 占size 
//    cout << "szie:" << mapStu.size() << endl;
//
//    cout << mapStu[100] << endl;
//    cout << "szie:" << mapStu.size() << endl;
//}
//void test01()
//{
//    multimap<int, string> mapStu;
//    mapStu.insert(make_pair(-1, "校长"));
//    mapStu.insert(make_pair(3, "校ds"));
//    mapStu.insert(make_pair(3, "htdbg"));
//    mapStu.insert(make_pair(12, "rs长"));
//    mapStu.insert(make_pair(32, "sdv长"));
//    mapStu.insert(make_pair(3, "aca"));
//    mapStu.insert(make_pair(3, "32456"));
//    mapStu.insert(make_pair(3, "da"));
//
//    multimap<int, string>::iterator it = mapStu.find(3);//返回符合键值为3的起始位置 ++ 是下一个键值为3的迭代器
//    int count = mapStu.count(3);  //返回符合键值为3的的对数量
//    for (int i = 0; i < count; i++)
//    {
//        cout << "key:" << (*it).first << " value:" << (*it).second << endl;
//        it++;
//
//    }
//}
//
//int main() {
//
//    test02();
//
//    system("pause");
//    return 0;
//}