#include <iostream>
using namespace std;
void quicksort(int* a, int l, int r) {
    if (l >= r) return;
    int lo = l;
    int hi = r;
    int key = a[lo];
    while (lo < hi) {
        while ((lo < hi) && (key <= a[hi])) hi--;
            a[lo] = a[hi];
        while ((lo < hi) && (key > a[lo])) lo++;
            a[hi] = a[lo];
    }
    a[lo] = key;
    
    quicksort(a, l, lo - 1);
    quicksort(a, lo + 1, r);
    
}
int main()
{
    int a[] = {2, 6, 3, 99, 5};
    quicksort(a, 0, 4);
    for (int e : a) cout << e << " ";
    cout << endl;
    return 0;
}