#include <iostream>
#include <vector>
using namespace std;
void select_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}
int main() {
    vector<int> a = {2, 6, 3, 99, 5};
    select_sort(a);
    for (int e : a) cout << e << " ";
    cout << endl;
    return 0;
}