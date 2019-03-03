#ifndef STACK
#define STACK
#include <iostream>
//顺序栈
class stack
{
public:
    stack(int c = 100){
        _capacity = c;
        T = new int[_capacity];
        _size = -1;
    }
    int top() const {
        if (_size > -1) return T[_size];
        std::cerr << "can't return top from empty stack" << std::endl;
        return -10086;
    };
    int empty() const {return _size == -1;};
    int size() const {return _size + 1;}
    void push(const int& e){
        //可以考虑加入上一个任务中的动态数组的扩容
        if (_size + 1 > _capacity) {
            std::cerr << " " << std::endl;
        }
        T[++_size] = e;
    }
    void pop() {
        if (this->empty()) {
            std::cerr << "can't pop from empty stack" << std::endl;
            return;
        }
        _size--;
    }
    ~stack(){
        delete [] T;
        T = nullptr;
    }
private:
    int _capacity;
    int _size;
    int* T;
};

//链式栈
struct ListNode{
    int val;
    ListNode *next;
    ListNode *pred;
    //查了一些东西 可能像单链表next指针这样关系不复杂
    //可以设计为unique_ptr这种但不要使用share_ptr消耗的资源很大
    //但是有种情况也是不能避免的 比如大量的删除操作 不断的会调用ptr的析构函数 栈可能会爆掉
    ListNode(int x): val(x), next(nullptr), pred(nullptr){}
};
class stack1 {
public:
    stack1(){
        head = new ListNode(0);
        tail = new ListNode(0);
        //链表的话还是使用尾插法保证元素的输入顺序
        head->next = tail; head->pred = nullptr;
        tail->pred = head; tail->next = nullptr;
        _size = 0;
    }
    ~stack1(){
      while (head != tail) {
            delete head;
            head = head->next;
        }
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    bool empty() const {return _size == 0;}
    void print() {
        ListNode* p = head->next;
        for(; p != tail; p=p->next)
            std::cout << p->val;
        std::cout << std::endl;
    }
    ListNode* push(const int& e) {
        _size++;
        ListNode* p = new ListNode(e);
        // tail->pred->next = p;
        // p->pred = tail->pred;
        // p->next = tail;
        // tail->pred = p;
        // 这样也是可以的 总之先断后链
        tail->pred->next = p;
        p->next = tail;
        p->pred = tail->pred;
        tail->pred = p;
        // 错误写法1 p->next = tail 直接清除了原有的链接
        // tail->pred->next 这时已经不指向自己(tail)了
        // 这里让我想起一到笔试题 让选择正确的链接方式 稍后补充
        // p->next = tail;
        // tail->pred = p;
        // tail->pred->next = p;
        // p->pred = tail->pred;
        return head;
    }
    void pop() {
        if (this->empty()) {
            std::cerr << "can't pop from empty stack" << std::endl;
            return;
        }
        _size--;
        ListNode* p = tail->pred;
        p->next->pred = p->pred;
        p->pred->next = p->next;
        delete p;
        p = nullptr;
    }
    int top() {
        if (this->empty()){
            std::cerr << "can't return top from empty stack" << std::endl;
            return -10086;
        }
        return tail->pred->val;
    }
private:
    ListNode* head;
    ListNode* tail;
    int _size;
};
#endif //STACK