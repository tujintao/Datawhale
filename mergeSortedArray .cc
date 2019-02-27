#include <vector>
#include <iostream>
using namespace std;
//类似归并的思路
void merge (vector<int>& tmp, vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j])
            tmp.push_back(nums1[i++]);
        else 
            tmp.push_back(nums2[j++]);
        
    }
    // cout << i << " " << j << endl;
    if (i < m) for (int t = i; t < m; ++t) tmp.push_back(nums1[t]);
    if (j < n) for (int t = j; t < n; ++t) tmp.push_back(nums2[t]);
} 
int main()
{
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {6,7};
    vector<int> c;
    merge(c, a, b);
    // for (int i = 0; i < k; ++i) 
    //     cout << c[i];
    for (int e : c) cout << e;
    return 0;
}