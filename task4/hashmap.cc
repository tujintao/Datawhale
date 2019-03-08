#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//设计思路
//定义一个指针数组作为hash表的桶table
//每当发生冲突的时候就在当前这个table上利用单链表把冲突的
//key和value链接到后面
struct node {
    int key;
    int val;
    int _size;
    node *next;
    node ();
    node (int k , int v) : key(k), val(v), next(nullptr){}
};
class HashMap{
public:
    HashMap(int c = 100){
        //创建指针数组并初始化
        table = new node*[_capacity = c]();
    }
    //每个桶设计为没有头结点的单链表，减少不必要的开销
    //key不存在的时候直接放进桶内，key存在的时候头插法链接到当前key后面
    void insert(int key, int val){
        key = (key + _capacity) % _capacity;
        // cout << key << endl;
        // cout << table[key] << endl;
        if (!hasKey(key)) {
            table[key] = new node (key, val);
            table[key]->_size++;
        } else {
            node *head = table[key];
            node *p = new node(key, val);
            p->next = head->next;
            head->next = p;
            table[key]->_size++;
        }
        // cout << table[key]->val << endl;
    }
    //返回key相同的结点的指针，得到一条单链表可遍历操作
    node* get(int key) {
        key = (key + _capacity) % _capacity;
        if (hasKey(key)){
            return table[key];
        } else {
            return nullptr;
        }
    }
    //没有头结点删除就很蛋疼。。然后就添加了个计数器_size
    //最后写的还是很蛋疼。。证明是设计问题还是该用带头结点的链表好处理的多
    void delItem (int key, int v){
        key = (key + _capacity) % _capacity;
        if (hasKey(key)) {
            if (table[key]->_size == 1) {
                if (table[key]->val == v) {
                    table[key]->_size--;
                    delete table[key];
                    //fk debug的半天悬垂指针没置空double free了
                    table[key] = nullptr;
                }                    
            } else if(table[key]->_size > 1) {
                node *head = get(key);
                //因为没有头结点，我们将下一个结点的数据与当前结点交换，再删除当前节点
                //比如有两个元素的时候，匹配到了第一个元素，我们因为没有头结点的信息
                //但我们可以这样做,交换两个结点的信息，删除下一个结点。注意考虑末尾元素
                //因为没有头结点要是第一个元素匹配，就得用上述方法
                //我这里是取巧了key相同交换val就可以了
                if (head->val == v) {
                    swap(head->val, head->next->val);
                    node *t = head->next;
                    head->next = head->next->next;
                    delete t;
                    t = nullptr;
                } else {
                //此时肯定有两个以上的元素
                //p
                // |
                // 1 2 3 4
                //   |
                //   p->next 
                    node *p = head;
                    while (p && p->next) {
                        if (p->next->val == v) break;
                        p = p->next;
                    }
                    // cout << p->val << endl;
                    node *t = p->next;
                    p->next = p->next->next;
                    delete t;
                    t = nullptr;
                }

            }
        }else {
            std::cerr << "结点不存在" << std::endl;
        }
    }
    bool hasKey(int key){return table[key] != nullptr;}
    ~HashMap(){
        // //对于桶内存在的每一条链都要释放
        for (int i = 0; i < _capacity; ++i) {
            if (table[i]) {
                node *head = table[i];
                while (head) {
                    node *tmp = head;
                    head = head->next;
                    delete tmp;
                }
            }
        }
        delete [] table;
    }
private:
    node** table;
    int _capacity;
};
int main()
{
    HashMap a;
    a.insert(5, 1);
    a.insert(5, 2);
    // a.insert(5, 3);
    // node *h = a.get(5);
    // a.delItem(5, 1);
    a.delItem(5, 2);
    node *h = a.get(5);
    while (h) {
        cout << h->key << " " << h->val << endl;
        h = h->next;
    }
    // node **p = new node*[100];
    // p[0] = new node(1, 1);
    // cout << p[0]->val << endl;
    // for (int i = 0; i < 100; ++i){
    //     if (p[i]){
    //         node *head = p[i];    
    //         while (head) {
    //             node* tmp = head;
    //             head = head->next;
    //             delete tmp;
    //         }
    //     }
    // }
    // delete [] p;
    // cout << p[0]->val << endl;
    // node *t = new node(1, 2);
    // t->next = p[0]->next;
    // p[0]->next = t;
    // node *tt = p[0];
    // while (tt) {
    //     cout << tt->val << endl;
    //     tt = tt->next;
    // }
    // shared_ptr<node> p(new node(2, 3));
    // cout << p->key << " " << p->val << endl;
    return 0;
}