#include "VECTOR.h"
#include <algorithm>

template<typename T> static bool lt(T& a, T& b){return a > b;}
#define  InHeap(n, i)      ( ( ( -1 ) < ( i ) ) && ( ( i ) < ( n ) ) ) //判断PQ[i]是否合法
#define  Parent(i)         ( ( i - 1 ) >> 1 ) //PQ[i]的父节点（floor((i-1)/2)，i无论正负）
#define  LastInternal(n)   Parent( n - 1 ) //最后一个内部节点（即末节点的父亲）
#define  LChild(i)         ( 1 + ( ( i ) << 1 ) ) //PQ[i]的左孩子
#define  RChild(i)         ( ( 1 + ( i ) ) << 1 ) //PQ[i]的右孩子
#define  ParentValid(i)    ( 0 < i ) //判断PQ[i]是否有父亲
#define  LChildValid(n, i) InHeap( n, LChild( i ) ) //判断PQ[i]是否有一个（左）孩子
#define  RChildValid(n, i) InHeap( n, RChild( i ) ) //判断PQ[i]是否有两个孩子
#define  Bigger(PQ, i, j)  ( lt( PQ[i], PQ[j] ) ? j : i ) //取大者（等时前者优先）
#define  ProperParent(PQ, n, i) /*父子（至多）三者中的大者*/ \
            ( RChildValid(n, i) ? Bigger( PQ, Bigger( PQ, i, LChild(i) ), RChild(i) ) : \
            ( LChildValid(n, i) ? Bigger( PQ, i, LChild(i) ) : i \
            ) \
            ) //相等时父节点优先，如此可避免不必要的交换
template<typename T> struct PQ {
    virtual void insert(T) = 0;
    virtual T getMax() = 0;
    virtual T delMax() = 0;
};
template <typename T>
class PQ_ComplHeap : public PQ<T>, public Vector<T>{
protected:
    int percolateDown(int n, int i); //下滤
    int percolateUp(int i);//上滤
    void heapify(int n);//建堆
public:
    PQ_ComplHeap() {}
    PQ_ComplHeap(T* A, int n){this->copyFrom(A, 0, n); heapify(n);}
    void insert(T);
    T getMax(){return this->_elem[0];};
    T delMax();
};
template <typename T> int PQ_ComplHeap<T>::percolateUp ( int i ) {
   while (ParentValid(i)) { //只要i有父亲（尚未抵达堆顶），则
      int j = Parent(i); //将i之父记作j
      if (lt(this->_elem[i], this->_elem[j])) break; //一旦当前父子不再逆序，上滤旋即完成
      std::swap(this->_elem[i], this->_elem[j]); i = j; //否则，父子交换位置，并继续考查上一层
   } 
   return i; //返回上滤最终抵达的位置
}
//vscode 里还是得指明作用域
template <typename T> void PQ_ComplHeap<T>::insert ( T e ) { //将词条插入完全二叉堆中
   Vector<T>::insert ( e ); //首先将新词条接至向量末尾
   percolateUp(Vector<T>::_size - 1); //再对该词条实施上滤调整
}
template <typename T> int PQ_ComplHeap<T>::percolateDown ( int n, int i ) {
   int j; //i及其（至多两个）孩子中，堪为父者
   while (i != (j = ProperParent(this->_elem, n, i))) //只要i非j，则
      {std::swap(this->_elem[i], this->_elem[j]); i = j; } //二者换位，并继续考查下降后的i
   return i; //返回下滤抵达的位置（亦i亦j）
}
template <typename T> void PQ_ComplHeap<T>::heapify ( int n ) { //Floyd建堆算法，O(n)时间
   for (int i = LastInternal(n); InHeap(n, i); i--) //自底而上，依次
      percolateDown(n, i); //下滤各内部节点
}
template <typename T> T PQ_ComplHeap<T>::delMax() { 
   T maxElem = this->_elem[0]; this->_elem[0] = this->_elem[ --Vector<int>::_size ]; //删除顶端元素 同时把末尾元素提到堆顶
   percolateDown ( Vector<T>::_size, 0 ); //对新堆顶实施下滤
   return maxElem; 
}
//因为是实现的是小顶堆，堆顶的元素一旦删除顺序就定了
// template <typename T> void Vector<T>::heapSort ( int lo, int hi ) { //0 <= lo < hi <= size
//    PQ_ComplHeap<T> H ( _elem + lo, hi - lo ); //将待排序区间建成一个完全二叉堆，O(n)
//    while (!H.empty()) //反复地摘除最大元并归入已排序的后缀，直至堆空
//       _elem[--hi] = H.delMax(); //等效于堆顶与末元素对换后下滤
// }

int main()
{
    int b[] = {11, 12, 2, 3, 5, 6, 7};
    PQ_ComplHeap<int> q(b, (int)sizeof(b) / sizeof(*b));
    int size = sizeof(b) / sizeof(*b);
    int j = 0;
    //堆排序
    //因为是实现的是小顶堆，堆顶的元素一旦删除顺序就定了
    //每一次下滤的复杂度都是O(n)
    while(q.size() && j < size) {
        b[j++] = q.delMax();
        // std::cout << q.delMax() << std::endl;
    }
    for (int e : b) std::cout << e << std::endl;
    return 0;
}