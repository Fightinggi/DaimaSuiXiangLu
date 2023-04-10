#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//����һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�
//
//candidates �е����ֿ����������ظ���ѡȡ��
//�����㷨 ��Ƕ��n��forѭ��
class Solution {
public:

    vector<int> path;
    vector<vector<int>> res;
    void back(vector<int>& candidates, int sum, int target, int index)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        // ��� sum + candidates[i] > target ����ֹ����
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)  //ͬһ����
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            back(candidates, sum, target, i);//����i+1�ˣ���ʾ�����ظ���ȡ��ǰ����
            sum -= candidates[i];
            path.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        if (candidates.size() == 0)
            return res;

        sort(candidates.begin(), candidates.end());
        back(candidates, 0, target, 0);
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
    vector<int> arr = { 2,3,6,7 };
    vector<vector<int>> res = s->combinationSum(arr, 7);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}