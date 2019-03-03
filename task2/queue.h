#ifndef QUEUE
#define QUEUE
//数组
class queue {
public:
    queue(int c = 100) {
        T = new int[_capacity = c];
        head = tail = 0;
    }
    ~queue(){
        delete [] T;
        T = nullptr;
    }
    bool empty() const {return head == tail;}
    int  size() const {return head == tail ? 0 : (tail - head);}
    int front() const{
        if (this->empty()) throw "can't return front from empty queue";
        return T[head+1];
    }
    int back() const{
        if (this->empty()) throw "can't return back from empty queue";
        return T[tail];
    }
    void push(const int& val) {
        if (tail > _capacity) throw "";//然后动态扩容就可以了
        T[++tail] = val;
    }
    void pop() {
        if (this->empty()) throw "can't pop from empty";
        if (head >_capacity) throw "";//所以可能还是一开始写成循环队列比较好
        head++;
    }
 
private:
    int *T;
    int _capacity;
    int head, tail;
};


//双向链表实现链式队列
struct ListNode{
    int val;
    ListNode *next;
    ListNode *pred;
    ListNode(int x) : val(x), next(nullptr), pred(nullptr){}
};
class queue1 {
public:
    queue1() {
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->pred = head;
        //然后发现之前写的双向循环列表根本不是循环列表 wszz 已更正
    }
    ~queue1() {
        while(head != tail) {
            delete head;
            head = head->next;
        }
        delete tail;
    }

    int size() const {return _size;}
    bool empty() const {return _size == 0;}
    int front() const {
        if (this->empty()) throw "can't return front from empty queue";
        return head->next->val;
    }
    int back() const {
        if (this->empty()) throw "can't return back from empty queue";
        return tail->pred->val;
    }
    void push(const int&  val) {
        ListNode* p = new ListNode(val);
        tail->pred->next = p;
        p->pred = tail->pred;
        p->next = tail;
        tail->pred = p;
        _size++;
    }
    void pop() {
        if (this->empty()) throw "can't pop from empty queue";
        ListNode* p = head->next;
        p->pred->next = p->next;
        p->next->pred = p->pred;
    }
private:
    ListNode* head;
    ListNode* tail;
    int _size, _capacity;
};

//循环队列

class queue2 {
public:
    queue2(int c = 100) {
        T = new int[_capacity = c];
        head = tail = 0;
    }
    ~queue2(){
        delete [] T;
        T = nullptr;
    }
    bool empty() const { return head == tail;}
    int  size() const {return _size;}
    int front() const{
        if (this->empty()) throw "can't return front from empty queue";
        return T[head];
    }
    int back() const{
        if (this->empty()) throw "can't return back from empty queue";
        return T[tail-1];
    }
    void push(const int& val) {
        if ((tail+1) % _capacity == head) throw "";
        _size++;
        T[tail] = val;
        tail = (tail + 1) % _capacity;
    }
    void pop() {
        if (this->empty()) throw "can't pop from empty";
        head = (head + 1) % _capacity;
        _size--;
    }
 
private:
    int *T;
    int _capacity;
    int head, tail;
    int _size;
};

#endif //QUEUE