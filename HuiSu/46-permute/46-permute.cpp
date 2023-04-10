#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//
//����һ�� û���ظ� ���ֵ����У����������п��ܵ�ȫ���С�
//
//ʾ�� :
//
//����: [1, 2, 3]
//��� : [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
class Solution {
public:

    //��Ž��
    vector<int> path;
    vector<vector<int>> res;

    //���ݺ���
    void back(vector<int>& nums, vector<bool>& used)
    {
        //������  ����Ҷ�ӽڵ� 
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        //��������
        for (int i = 0; i < nums.size(); i++)
        {
            //����if (used[i] == true) continue; // path���Ѿ���¼��Ԫ�أ�ֱ������
            //��Ŀ����
            if (used[i] == false)
            {
                //�ݹ�
                used[i] = true;
                path.push_back(nums[i]);
                back(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        back(nums, used);
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
    vector<int> arr = {1,2,3 };
    vector<vector<int>> res = s->permute(arr);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}
