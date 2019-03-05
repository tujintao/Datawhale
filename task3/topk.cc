#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>
using namespace std;
//解法三
int partation(vector<int>& a, int lo, int hi) {
    int key = a[lo];
    //这里是把大的元素放在前面了，这样是因为划分好处理
    while (lo < hi) {
        while (lo < hi && key >= a[hi]) hi--;
        a[lo] = a[hi];
        while (lo < hi && key < a[lo]) lo++;
        a[hi] = a[lo];
    }
    a[lo] = key;
    return lo;
}
int findK(vector<int>& nums, int lo, int hi, int k) {
    int p = partation(nums, lo, hi);
    if (k == p - lo + 1) return nums[p];
    else if (k > p - lo + 1)//说明在Sb这段，要继续往后找Sb中最大的K - |Sa|个元素
        return findK(nums, p + 1, hi, k - p + lo - 1);
    else
        return findK(nums, lo, p - 1, k);
        
}

//解法四
int GreaterNum(float array[], int len, float num)
{
	int n = 0;
	for (int i = 0; i < len; i++) {
		if (array[i] >= num)
			n++;	
	}
	
	return n;
}
float BinarySearchKth(float array[], int len, int K)
{
	float v_min, v_max;
	v_min = numeric_limits<float>::max();
	v_max = numeric_limits<float>::min();
	for (int i = 0; i < len; i++) {
		v_min = min(v_min, array[i]);
		v_max = max(v_max, array[i]);	
	}
	
	//寻找区间[v_min, v_max]，第K大的数就在这个区间内 
	float delta = 0.5f;
	while (v_max - v_min > delta) {
		float v_mid = v_min + (v_max - v_min) * 0.5;
		if ( GreaterNum(array, len, v_mid) >= K )
			v_min = v_mid;
		else
			v_max = v_mid; 	
	}
	 
	float kth_number;
	for (int i = 0; i < len; i++) {
		if (array[i] >= v_min && array[i] <= v_max) {
			kth_number = array[i];
			break;	
		}	
	}
	return kth_number;
}
//解法5
// priority_queue<int> ch;
//这里我们要声明的是小顶堆
priority_queue<int, vector<int>, greater<int> > ch;
//自定义数据结构时
// auto cmp = [](T a, T b){return a.val < b.val;}
// // priority_queue<T, vector<T>, decltype(cmp)> ch(cmp);
int Kth_complPQ(vector<int>& a, int k) {
    for (int e : a) {
        if (ch.size() < k) {
            ch.push(e);
        } else if (ch.top() < e) { //最小堆比堆顶元素大的进队
            ch.pop();
            ch.push(e);
        }
    }

    return ch.top();
}
//在复习的堆的实现与性质后根据伪码实现的

int main()
{
    vector<int> a = {2, 6, 3, 99, 5};
    float b[] = {2, 6, 3, 99, 5};
    // cout << numeric_limits<double>::max();
    cout << BinarySearchKth(b, sizeof(b)/sizeof(float), 4) << endl;
    cout << findK(a, 0, a.size() - 1, 4) << endl;
    cout << Kth_complPQ(a, 4) << endl;
    // cout << Kth_comlheap(a, 4) << endl;
    return 0;
}