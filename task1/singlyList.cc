#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
    // ListNode(int x, ListNode* _next) : val(x), next(_next){}
};

class singlyList {
public:
    singlyList() {
        head = new ListNode(0);
        tail = new ListNode(0);
        tail = head;
        //有头尾两个节点做哨兵处理起来也方便
        //还是有点问题的先调用尾插再调用头插的时候要把tail移到尾部
        _size = 0;
    }
    ~singlyList(){
       ListNode* p = head->next;
       while(p) {
           delete p;
           p = p->next;
       }
       delete  head;
       //double free
    //    delete  tail;
    }
    ListNode* insert1(const int& e);
    ListNode* insert2(const int& e);
    ListNode* remove(const int& e);
    void print();
private:
    ListNode *head, *tail;
    int _size;
};
void singlyList::print() {
    ListNode* p = head->next;
    for(; p; p=p->next)
        cout << p->val;
    cout << endl;
}
ListNode* singlyList::insert1(const int& e) {
    //头插法
    ListNode* p = new ListNode(e);
    p->next = head->next;
    head->next = p;
    return head;
}
ListNode* singlyList::insert2(const int& e) {
    //尾插法;
    tail->next = new ListNode(e);
    tail = tail->next;
    return head;
}
ListNode* singlyList::remove(const int& e) {
    ListNode* pre = nullptr;
    ListNode* p = head->next;
    while (p) {
        if (p->val == e) break;
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    delete p;
    return head;
}
int main()
{
    // 测试 头插
    singlyList a;
    a.insert1(1);
    a.insert1(2);
    a.insert1(3);
    a.print();
    //测试 尾插
    singlyList b;
    b.insert2(1);
    b.insert2(2);
    b.insert2(3);
    b.print();
    //测试 删除
    b.remove(2);
    b.print();
    //混合调用 出错尾指针没有更新
    // a.insert2(1);
    // a.insert2(2);
    // a.insert(3);
    // a.print();
    // a.remove(2);
    // a.print();
    //删除
    return 0;
}