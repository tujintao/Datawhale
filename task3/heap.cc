#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class heap
{
public:
    //T(new int[_capacity], default_delete<T[]>()) 如果是shared_ptr的话 注意重写这个deletor
    heap(int size = 100):_size(0),_capacity(size), T(new int[_capacity]){
    }
    void push(int x){
         //当前节点的编号
         // 如果是share_ptr分配的动态数组 没有提供[]操作 可以转回裸指针然后再操作
         //auto h = T.get();
         //h[x]
         int i = _size++, p;
         while (i > 0) {
             //父节点的编号
              p = (i - 1) / 2;

             // 如果已经没有大小颠倒则退出
             if (T[p] <= x) break;
             //把父节点的数值放下来,而把自己提上去
             T[i] = T[p];
             i = p;
         }
         T[i] = x;
    }
    int pop() {
        //最小值
        int ret = T[0];
        //提到根的数值
        int x = T[--_size];
        int i = 0;
        while (i * 2 + 1 < _size) {
            int lchild = i * 2 + 1, rchild = i * 2 + 2;
            if (rchild < _size && T[rchild] < T[lchild]) lchild = rchild; 

            //如果没有大小颠倒则退出
            if (T[lchild] >= x) break;

            T[i] = T[lchild]; 
            i = lchild;
        }
        T[i] = x;
        return ret;
    }
private:
    int _capacity;
    int _size;
    // shared_ptr<int[]> T;
    //C++11中 unique_ptr 对动态数组提供了支持 提供下表操作
    unique_ptr<int[]> T;
};
int main()
{
    vector<int> a = {2, 3 , 0, 1, 10};
    heap h(100);
    for (int e : a) h.push(e);
    for (int i  = 0; i < a.size(); ++i){
      cout << h.pop() << endl;
      
    }
    return 0;
}