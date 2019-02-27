#include <iostream>
template<typename T> class Array
{
public:
    Array(int s, int _capacity = 10){//固定长度的有序数组 假设是内置类型 int char 这两种
        _elem = new T[_size = s];
    }
    ~Array(){delete [] _elem;}
    bool insert(int pos, T const& e);
    bool erase(int pos);
    int modify(int pos, T const& e) {return pos > _size ? -1 : (_elem[pos] = e);}
    int size() const {return _size;}
    //为了方便访问重载[]运算符
    T& operator[](int pos)const {return _elem[pos];};
    //因为是有序数组 可以通过二分查找访问元素;
    T upper_bound(int lo, int hi, T const& key);//[lo, hi)
    void print() { for (int i = 0; i < _size; ++i) std::cout << _elem[i]; std::cout<<std::endl;};
protected:
    void shrink();
    void expand();
private:
    T* _elem;
    int _size, _capacity;
};
//这一回我就只写了个简化版本的shrink() 和 expand() 只增加或删除一个位置
//直接合并到insert remove中了
template<typename T> bool Array<T>::insert(int pos, T const& e) {
    //出入位置不合法的情况
    if (pos < 0 || pos > _size) return -1;
    if (_size >= _capacity) {
        T* oldelem = _elem; _elem = new T[_capacity = _size++];
        for (int i = 0; i < _size - 1; ++i) _elem[i] = oldelem[i];
        delete [] oldelem;
    }
    for (int i = _size; i > pos; --i) _elem[i] = _elem[i-1];
    _elem[pos] = e;
}
template<typename T> bool Array<T>::erase(int pos) {
    if (pos < 0 || pos > _size) return -1;
    for (int i = pos; i <= _size - 1; ++i)
        _elem[i] = _elem[i+1];
    _size--;
    //
}
template<typename T> T Array<T> :: upper_bound(int lo, int hi, T const& key) {
    if (lo < 0 || hi > _size) {
        std::cerr << "index boundary error" << std::endl;
    }
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (_elem[mid] == key) return mid;
        else if (_elem[mid] > key)
            hi = mid;
        else 
            lo = mid + 1;
    }
    return lo;//因为是upper_bound如果元素不存在会返回最接近的上界
}
int main()
{
    Array<int> a(10);
    for (int i = 0; i < a.size(); ++i)
        a[i] = i;
    //测试 插入
    a.insert(10, 999);
    a.print();
    std::cout << a.size() << std::endl;
    //测试 删除
    a.erase(10);
    a.print();
    //测试 修改
    a.modify(9, 666);
    a.print();
    // for (int = )
    std::cout << a.upper_bound(0, a.size(), 5);
    std::cout << a.upper_bound(0, a.size(), 9);
    return 0;
}