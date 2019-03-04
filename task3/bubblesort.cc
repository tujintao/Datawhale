#include<iostream>
using namespace std;
void bubblesort(int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}
int main()
{
    int a[] = {2, 6, 3, 99, 5};
    bubblesort(a, 5);
    for (int e : a) cout << e << " ";
    cout << endl;
    return 0;
}