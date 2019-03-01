#include "stack.h"
using namespace std;
int main()
{
    // stack a;
    // a.pop();
    // cout << a.top() << endl;
    // a.push(1);
    // cout << a.size() << endl;
    // cout << a.top() << endl;
    // a.pop();
    // cout << a.size() << endl;
    // a.push(3);
    // cout << a.top();
    //_______________________
    //链式栈
    stack1 b;
    b.push(3);
    b.push(1);
    b.print();
    b.pop();
    b.print();
    cout << b.top() << endl;
    b.pop();
    b.pop();
    b.top();
    return 0;
}