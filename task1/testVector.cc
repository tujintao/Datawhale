#include "VECTOR.h"
#include <iostream>
int main(){
    //测试 构造函数
    Vector<int> a(100, 10, 1);
    std::cout << a.size() << std::endl;
    //测试 []运算符
    Vector<char> b(10, 9, 'c');
    for (int i = 0; i < 9; ++i)
        std::cout << b[i];
    //测试 拷贝赋值
    Vector<char> c(b);
    for (int i = 0; i < c.size(); ++i) std::cout << c[i];
    std::cout << std::endl;
    //符合边界条件的插入[0, b.size())
    b.insert(b.size(), 'a');
    for (int i = 0; i < b.size(); ++i) std::cout << b[i];
    std::cout << std::endl;
    //不合法的边界插入
    // c.insert(c.size() + 1, 's');
    // for (int i = 0; i < c.size(); ++i) std::cout << b[i];
    // std::cout << std::endl;
    // 报错 没有处理不合法的插入 (已修改)
    
    //测试 删除某个下标的元素
    b.remove(b.size()-1);
    for (int i = 0; i < b.size(); ++i) std::cout << b[i];
    std::cout << std::endl;
    //测试 范围删除
    b.remove(0, 5);
    for (int i = 0; i < b.size(); ++i) std::cout << b[i];
    std::cout << std::endl;
    return 0;
}