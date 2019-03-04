#include <iostream>
#include <memory>
using namespace std;
void merge(int* a, int lo, int mid, int hi){
    int *tmp = new int[hi - lo + 1];
    int i = lo, j = mid, k = 0;
    while (i <= mid && j <= hi) {
        if (a[i] < a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= hi) tmp[k++] = a[j++];
    for (int i = 0, k = lo; k <= hi;)
        a[k++] = tmp[i++];
    delete [] tmp;
}
void merge_sort(int* a, int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    merge_sort(a, lo, mid);
    merge_sort(a, mid + 1, hi);
    merge(a, lo, mid + 1, hi);
}
int main() {
    int a[] = {11, 12, 2, 3, 5, 6, 7};
    merge_sort(a, 0, 6);
    for (int e : a) cout << e;
    cout << endl;
    return 0;   
}