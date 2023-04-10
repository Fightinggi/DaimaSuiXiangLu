#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <unordered_set>
using namespace std;
//����һ����������, ����������ҵ����и�����ĵ��������У����������еĳ���������2��
//
//ʾ�� :
//
//����: [4, 6, 7, 7]
//��� : [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7, 7], [4, 7, 7]]

//�����㷨 ��Ƕ��n��forѭ��
class Solution {
public:

    //��Ž��
    vector<int> path;
    vector<vector<int>> res;

    //���ݺ���
    void back(vector<int>& nums, int start_index)
    {
        //������
        if (path.size() > 1) res.push_back(path);

        //��֦�ݹ��߼�  uset֧�ӱ������ȥ�ز���
        unordered_set<int> uset;  //ÿ����һ�εݹ飬����ÿ��һ�㣬��������uset��

        //���� ���㼯���е�Ԫ�أ��ڵ㺢�ӵ�����==���ϵĴ�С
        for (int i = start_index; i < nums.size(); i++)
        {
            //����ȥ���߼� set  
            //nums[i]ȡ����һ���� С�� ����������������һ��ȡ������ ����������ѭ��
            //ȥ�أ�����������ͬ����
            if (!path.empty() && nums[i] < path.back()
                || uset.find(nums[i]) != uset.end())
                continue;
            //�ݹ� ����
            uset.insert(nums[i]);// // ��¼���Ԫ���ڱ����ù��ˣ�������治��������,����Ҫ������
            path.push_back(nums[i]);
            back(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        back(nums, 0);
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
    vector<int> arr = {4,6,7,7 };
    vector<vector<int>> res = s->findSubsequences(arr);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}
