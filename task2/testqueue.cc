#include "queue.h"
#include <iostream>
using namespace std;
int main()
{
    // queue a;
    // a.push(1);
    // cout << a.front() << endl;
    // cout << a.back() << endl;
    // a.push(2);
    // cout << a.front() << endl;
    // cout << a.back() << endl;
    // cout << a.size() << endl;
    // a.pop();
    // a.pop();
    // cout << a.size() << endl;
    
    // a.pop();
    // queue1 b;
    // b.push(1);
    // cout << b.front() << endl;
    // cout << b.back() << endl;
    // b.push(2);
    // cout << b.size() << endl;
    // b.pop();
    //  cout << b.front() << endl;
    // cout << b.back() << endl;
    queue2 c;
    c.push(1);
    // cout << c.front() << endl;
    // cout << c.back() << endl;
    c.push(2);
    c.push(3);
    // c.size();
    c.pop();
    cout << c.front() << endl;
    cout << c.back() << endl;

    return 0;
}