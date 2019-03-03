#include <iostream>
#include <vector>
using namespace std;
int Fibonacci(int n) {
    if (n == 1 || n == 2) return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int Fac(int n) {
    if (n == 0) return 1;
    return n * Fac(n-1);
}
 void dfs(const vector<int>& nums, vector<int>& cur, vector<vector<int> >& ans, vector<int>& used) {
        if(cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(used[i]) continue;
            cur.push_back(nums[i]);
            used[i] = 1;
            dfs(nums, cur, ans, used);
            used[i] = 0;
            cur.pop_back();
        }
    }
int main()
{
    cout << Fibonacci(3) << endl;
    vector<int> nums = {1, 2, 3};
    vector<vector<int> > ans;
    vector<int> used(nums.size());
    vector<int> cur;
    dfs(nums, cur, ans, used);
    for (auto e : ans) {
        for (auto i : e) cout << i;
        cout << endl;
    }
    return 0;
}