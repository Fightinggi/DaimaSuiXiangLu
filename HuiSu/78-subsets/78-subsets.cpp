#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
//�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��
//���룺nums = [1, 2, 3]
//����� [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
//��ô�������ͷָ����ⶼ���ռ�����Ҷ�ӽڵ㣬���Ӽ����������������нڵ㣡
class Solution {
public:

    //��Ž��
    vector<int> path;
    vector<vector<int>> res;


    //���ݺ���
    void back(vector<int>& nums, int start_index)
    {
        //������
        res.push_back(path);

        //��ֹ����
        if (start_index >= nums.size())
        {
            return;
        }
        //��������
        for (int i = start_index; i < nums.size(); i++) //{1,2}��{2,1}����һ������
        {
            path.push_back(nums[i]);
            back(nums, i + 1);//{1,2}��{2,1}����һ������
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        res.clear();
        path.clear();
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
    cout << "[";

    for (vector<vector<int>>::iterator i = A.begin(); i != A.end(); i++) {
        cout << "[";
        
        for (vector<int>::iterator j = i->begin(); j != i->end(); j++) {
            cout << *j << ",";
        }

        cout << "],";
        //cout << endl;
    }
    cout << "]";
    /*cout << endl;*/
}
void test()
{
    Solution* s = new Solution();
    vector<int> in = { 1,2,3 };
    vector<vector<int>> res = s->subsets(in);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}