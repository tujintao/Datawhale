#ifndef VECTOR
#define VECTOR
#define DEFAULT_CAPACITY 3
#include <iostream>
template<typename T> class Vector {
public:
    Vector (int c = DEFAULT_CAPACITY,int s = 0, T val = 0) {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _size++) _elem[_size] = val;
    }
    //vector<int> b(n, vector<int>(m)); 这种二维该怎么实现呢 这个查了下实在是不会写。
    Vector (const Vector<T>& x);
    ~Vector() {delete []_elem;}
    int size () const {return _size;}
    bool empty() const {return _size == 0;}
    //实现增删改
    int insert(int pos, T const& e);
    int insert(T const & e) { return insert(_size, e);}
    T remove(int pos);
    int remove(int lo, int hi);
    T& operator[] (int pos) const{return _elem[pos];}
    Vector<T> & operator=(Vector<T> const &);
    void heapSort(int lo, int hi);
protected:
    void expand();
    void shrink();
    void copyFrom(T const* A, int lo, int hi);
    int _size; T _capacity;
    T* _elem;
};
template<typename T> Vector<T> :: Vector(const Vector<T>& v){
    _elem = new T[v._capacity];
    for (_size = 0; _size < v.size(); ++_size) _elem[_size] = v[_size];
}
template<typename T> void Vector<T> :: expand() {
    //申请新的地址 复制数据 释放旧的数据
    if (_size < _capacity) return;
    if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T* oldElem = _elem; T* elem = new T[_capacity <<= 1];
    //扩容策略可以是 1 ~ 2倍 或者 2倍 后面有总结
    for (int i = 0; i < _size; ++i)
        _elem[i] = oldElem[i];
    delete [] oldElem;
} 
//为什么要缩容
template<typename T> void Vector<T> :: shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1) return;//不致收缩到DEFAULT_
    //不致收缩到DEFAULT_CAPACITY
    if (_size<<2 > _capacity) return; //只有利用率低于 25%的时候才进行缩容
    T* oldElem = _elem; _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; ++i) _elem[i] = oldElem[i];
    delete [] oldElem;
}
template<typename T> int Vector<T> :: insert(int pos, T const& e) {
    if (pos > _size) { 
        std::cerr << "insert_out_of_range" << std::endl;
        return -1;
    }
    //仓促的处理了一下，主要是没想清楚怎么输出错误信息，想抛异常异常但感觉不太合适，之后讨论下吧
    expand();
    for (int i = _size; i > pos; --i) _elem[i] = _elem[i-1];
    _elem[pos] = e;
    _size++;
    return e;
}
template <typename T>
void Vector<T>::copyFrom(T const* A, int lo, int hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi) 
        _elem[_size++] = A[lo++];
}
template <typename T> int Vector<T>::remove(int lo, int hi) {
    //[lo, hi)
    if (lo > hi) {std::cerr << "index error" << std::endl;}
    if (lo == hi) return 0;
    while (hi < _size) _elem[lo++] = _elem[hi++];//从[hi,size)顺次前移hi - lo个单元
    _size = lo;
    shrink();
    return hi - lo;
}
template <typename T> T Vector<T>::remove(int pos) {
    if (pos > _size) {std::cerr<<"index_out_of_range"<<std::endl;return -1;}
    T e = _elem[pos];
    remove(pos, pos + 1);//[pos, pos + 1)

}
template <typename T> Vector<T>& Vector<T>::operator=(Vector<T> const & V ) {
    if (_elem) delete [] _elem;
    copyFrom(V._elem, 0, V.size());
    return *this;
}
#endif // VECTOR