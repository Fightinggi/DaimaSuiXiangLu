#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <map>
using namespace std;
//����һ����Ʊ���ַ�����ά����[from, to]���������е�������Ա�ֱ��ʾ�ɻ������ͽ���Ļ����ص㣬�Ը��г̽������¹滮����������Щ��Ʊ������һ���� JFK������Ϲ��ʻ��������������������Ը��г̱���� JFK ��ʼ��
//
//��ʾ��
//
//������ڶ�����Ч���г̣����㰴�ַ���Ȼ���򷵻���С���г���ϡ����磬�г�["JFK", "LGA"] ��["JFK", "LGB"] ��Ⱦ͸�С���������ǰ
//���еĻ�������������д��ĸ��ʾ���������룩��
//�ٶ����л�Ʊ���ٴ���һ�ֺ�����г̡�
//���еĻ�Ʊ���붼��һ�� �� ֻ����һ�Ρ�
//ʾ�� 1��
//
//���룺 [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//�����["JFK", "MUC", "LHR", "SFO", "SJC"]
//�����㷨 ��Ƕ��n��forѭ��
class Solution {
public:


    //��Ž��
    vector<string> res;
    //��ų���-�ﵽ��ӳ���ϵ, ͬused���ã���¼�ù��Ļ�Ʊ
    //unordered_map<��������, map<�������, �������>> targets
    map<string, map<string, int>> targets;

    //���ݺ���
    bool back(vector<string>& res, int ticketNum)  // Ψһ��  bool
    {
        //��ֹ����  ��Ʊ��==�г���  ÿ�ݹ�һ�Σ�������ȼ�һ���ͻ��ж�һ�Σ��ͼ�һ��
        if (res.size() == ticketNum + 1)
        {
            return true;
        }
        //��������  �������г̵����һ�и��ط����� �� �������г�Ʊ�Ļ�������Щ���е�push_back
        // ��������JFK�ܵ�����Щ�򵽻�����ȥ����intֵ=0
        for (pair<const string, int>& tar : targets[res[res.size() - 1]])
        {
            if (tar.second > 0)  //˵����ȥĿ�Ļ����Ļ�Ʊ
            {
                tar.second--;  //ȥ���˼�һ��
                res.push_back(tar.first);
                if (back(res, ticketNum)) return true;
                res.pop_back();
                tar.second++;//���ݣ�����г̲��У����أ���Ʊ������
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
        //��ʼ�� targets ��¼ӳ���ϵ
        for (const vector<string>& tic : tickets)
        {
            targets[tic[0]][tic[1]]++;
        }
        res.push_back("JFK");
        back(res, tickets.size());
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