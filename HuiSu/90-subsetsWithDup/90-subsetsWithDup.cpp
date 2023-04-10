#include<vector>
#include<queue>
#include<iostream>
#include<stack>
#include<string>
#include <unordered_set>
using namespace std;
//����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����
//
//˵�����⼯���ܰ����ظ����Ӽ���
//
//ʾ�� :
//
//����: [1, 2, 2]
//��� : [[2], [1], [1, 2, 2], [2, 2], [1, 2], []]
//===============ector<bool>& used=================
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // used[i - 1] == true��˵��ͬһ��֦candidates[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����candidates[i - 1]ʹ�ù�
            // ������Ҫ��ͬһ����ʹ�ù���Ԫ�ؽ�������
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // ȥ����Ҫ����
        backtracking(nums, 0, used);
        return result;
    }
};
//===================unordered_set<int> uset;=================
class Solution2 {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            if (uset.find(nums[i]) != uset.end()) { // ����ҵ���ͬ��Ԫ�أ���������ѭ��
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // ������Ϊ�� ֱ���ж��������ڵ��Ƿ���ȼ��ɡ�
        backtracking(nums, 0);
        return result;
    }
};

// =================if (i > startIndex && nums[i] == nums[i - 1])=====================
class Solution3 {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // ������Ҫ��ͬһ����ʹ�ù���Ԫ�ؽ�������
            if (i > startIndex && nums[i] == nums[i - 1]) { // ע������ʹ��i > startIndex
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // ȥ����Ҫ����
        backtracking(nums, 0);
        return result;
    }
};


//�º��� ��ӡһά���� vector<string>
template<typename T>
struct print002 {
    void operator()(T val) {
        cout << val << " ";
    }
};
template<typename T>
void print_vector_str(vector<T> res)
{
    //�º���  ��������ʹ��
   /* for_each(res.begin(), res.end(), print002<T>());
    cout << endl;*/

    //��������
    for_each(res.begin(), res.end(), [](T val) { cout << val << ";"; });
    cout << endl;
}
//��ӡ��ά����
template<typename T>
void PrintVecofVec2(vector<vector<T>>& res) {
    for (auto& rowV : res) {
        for (auto& el : rowV) {
            cout << el << " ";
        }
        cout << "; ";
    }
    cout << endl;
}
void test()
{
    Solution* s = new Solution();
    string in = "25525511135";
    vector<int> nums = { 1,2,2 };
    vector<vector<int>> res = s->subsetsWithDup(nums);
    PrintVecofVec2<int>(res);
    //PrintVecofVec1<string>(res);

}
int main()
{
    test();
    return 0;
}