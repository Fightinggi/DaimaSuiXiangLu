#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



//�������� ά�����ֵ ÿ�ζ��н���Ԫ��val  ����pop_back����valС��Ԫ��
//ά�����ֵ  ������ֵ�ǻ���������ǰ�ƶ�ʱ����һ��pushǰ�� ��Ҫpop��Ԫ�� ��pop  ��push  pushǰ�ȱȽϴ�С
//ά�����ֵ��Ŀ���� deque��front��Զ�Ƕ���������  ����λ�ò�����

class Solution {
private:
    class MyQueue { //�������У��Ӵ�С��  
    public:
        deque<int> que; // ʹ��deque��ʵ�ֵ�������  //deque  ���˶����Խ���pop��push����
        // ÿ�ε�����ʱ�򣬱Ƚϵ�ǰҪ��������ֵ�Ƿ���ڶ��г���Ԫ�ص���ֵ���������򵯳���
        // ͬʱpop֮ǰ�ж϶��е�ǰ�Ƿ�Ϊ�ա�
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();//��ǰ�ƶ�һλ
            }
        }
        // ���push����ֵ�������Ԫ�ص���ֵ����ô�ͽ����к�˵���ֵ������ֱ��push����ֵС�ڵ��ڶ������Ԫ�ص���ֵΪֹ��
        // �����ͱ����˶��������ֵ�ǵ����Ӵ�С���ˡ�
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // ��ѯ��ǰ����������ֵ ֱ�ӷ��ض���ǰ��Ҳ����front�Ϳ����ˡ�
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) { // �Ƚ�ǰk��Ԫ�طŽ�����
            que.push(nums[i]);   // ��� 3 -1
        }
        result.push_back(que.front()); // result ��¼ǰk��Ԫ�ص����ֵ
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            // ���������Ƴ���ǰ��Ԫ��  ���û����ִ��pop������˵������һ��push������ʱ���Ѿ�pop��С��Ԫ����
            //�������ִ��pop������˵��pop��ֵ�ǻ���������Ҫ��ֵҲ������ֵ ����frontλ�á�
            que.push(nums[i]); // ��������ǰ����������Ԫ��
            result.push_back(que.front()); // ��¼��Ӧ�����ֵ
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
////��ֵ�����ظ�
//// 
////3.8.2.1 map���캯��
////map<T1, T2> mapTT;//mapĬ�Ϲ��캯��: 
////map(const map& mp);//�������캯��
////
////
////3.8.2.2 map��ֵ����
////map & operator=(const map & mp);//���صȺŲ�����
////swap(mp);//����������������
////
////3.8.2.3 map��С����
////size();//����������Ԫ�ص���Ŀ
////empty();//�ж������Ƿ�Ϊ��
////3.8.2.4 map��������Ԫ�ز���
////map.insert(...); //����������Ԫ�أ�����pair<iterator,bool>
////map<int, string> mapStu;
////// ��һ�� ͨ��pair�ķ�ʽ�������
////mapStu.insert(pair<int, string>(3, "С��"));
////// �ڶ��� ͨ��pair�ķ�ʽ�������
////mapStu.inset(make_pair(-1, "У��"));
////// ������ ͨ��value_type�ķ�ʽ�������
////mapStu.insert(map<int, string>::value_type(1, "С��"));
////// ������ ͨ������ķ�ʽ����ֵ
////mapStu[3] = "С��";
////mapStu[5] = "С��";
////3.8.2.5 mapɾ������
////clear();//ɾ������Ԫ��
////erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
////erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
////erase(keyElem);//ɾ��������keyΪkeyElem�Ķ��顣
////3.8.2.6 map���Ҳ���
////find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
////count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
////lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
////upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������	
////equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������
//
////�ı����
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
//    // ��һ�� ͨ��pair�ķ�ʽ�������
//    mapStu.insert(pair<int, string>(3, "С��"));
//    // �ڶ��� ͨ��pair�ķ�ʽ�������
//    mapStu.insert(make_pair(-1, "У��"));
//    // ������ ͨ��value_type�ķ�ʽ�������
//    mapStu.insert(map<int, string>::value_type(1, "С��"));
//    // ������ ͨ������ķ�ʽ����ֵ
//    mapStu[3] = "С��";
//
//    print<map<int, string, compare>>(mapStu); //print(mapStu);
//
//    //[]����ʱ û��ʵֵ ���м�ֵ ռsize 
//    cout << "szie:" << mapStu.size() << endl;
//
//    cout << mapStu[100] << endl;
//    cout << "szie:" << mapStu.size() << endl;
//}
//void test01()
//{
//    multimap<int, string> mapStu;
//    mapStu.insert(make_pair(-1, "У��"));
//    mapStu.insert(make_pair(3, "Уds"));
//    mapStu.insert(make_pair(3, "htdbg"));
//    mapStu.insert(make_pair(12, "rs��"));
//    mapStu.insert(make_pair(32, "sdv��"));
//    mapStu.insert(make_pair(3, "aca"));
//    mapStu.insert(make_pair(3, "32456"));
//    mapStu.insert(make_pair(3, "da"));
//
//    multimap<int, string>::iterator it = mapStu.find(3);//���ط��ϼ�ֵΪ3����ʼλ�� ++ ����һ����ֵΪ3�ĵ�����
//    int count = mapStu.count(3);  //���ط��ϼ�ֵΪ3�ĵĶ�����
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