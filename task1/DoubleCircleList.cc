#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode *pre;
    ListNode(int x) : val(x), next(nullptr), pre(nullptr){}
};
//
class Dlist{
public:
    Dlist(){
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->pre = head;
        tail->next = head;
        head->pre = tail;
    }
    void print();
    bool empty() const {return head->next == tail;}
    ~Dlist() {
        while (head != tail) {
            delete head;
            head = head->next;
        }
        delete tail;
    }
    ListNode* insert(const int& e);
    void remove(const int& e);
private:
    ListNode* head;
    ListNode* tail;
};
void Dlist::print() {
    ListNode* p = head->next;
    for(; p != tail; p=p->next)
        cout << p->val;
    cout << endl;
} 
ListNode* Dlist::insert(const int& e) {
    ListNode* p = new ListNode(e);
    tail->pre->next = p;
    p->pre = tail->pre;
    p->next = tail;
    tail->pre = p;

    return head;
}

void Dlist::remove(const int& e) {
    ListNode* pos = head;
    for (; pos != tail; pos = pos->next) {
        if (pos->val == e) break;
    }
    pos->pre->next = pos->next;
    pos->next->pre = pos->pre;
    delete pos;
}
int main()
{   
    Dlist a;
    cout << a.empty() << endl;
    a.insert(3);
    cout << a.empty() << endl;
    a.insert(4);
    a.print(); 
    a.remove(3);
    a.print();
    return 0;
}