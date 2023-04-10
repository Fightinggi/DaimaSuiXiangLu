#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
//�ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�
//�����㷨 ��Ƕ��n��forѭ��
class Solution {
private:
    vector<vector<int>> result; // ��Ž����
    vector<int> path; // ���������Ľ��
    void backtracking(int targetSum, int k, int sum, int startIndex) {  //==========startIndex ���Ͽ�ʼ��λ��============

        if (sum > targetSum) { // ��֦����
            return; // ���path.size() == k ��sum != targetSum ֱ�ӷ���
        }

        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) { // ��֦
            sum += i; // ����
            path.push_back(i); // ����
            // if(sum>target) //��֦����
            // {
            //     sum-=i;  �������� ����
            //     path.pop_back();  ����
            //     return;
            // }
            backtracking(targetSum, k, sum, i + 1); // ע��i+1����startIndex  //index+1 ��ʾ������һ��ݹ�ʱ����ʼλ��ǰ��һλ�����ظ�ʹ�õ�ǰ����
            sum -= i; // ����
            path.pop_back(); // ����
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // ���Բ���
        path.clear();   // ���Բ���
        backtracking(n, k, 0, 1);
        return result;
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
    vector<vector<int>> res = s->combinationSum3(3, 9);
    printvector2(res);
}
int main()
{
    test();
    return 0;
}