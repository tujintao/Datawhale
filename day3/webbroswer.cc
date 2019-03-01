#include <iostream>
#include <stack>
#include <string>
using namespace std;
class history{
public:
    history(){
        while (front.size()) front.pop();
        while (back.size()) back.pop();
    }
    ~history() {
        while (front.size()) front.pop();
        while (back.size()) back.pop(); 
    }
    void isWatching(const string& s){
        //如果是第一次观看那么应该是不可以跳转的
        //front的栈顶是我们当前访问的网址
        // cout << front.size() << endl;
        // if (front.empty()) {
        //     front.push(s);
        // } else if (front.size() > 1) {
        //     back.push(front.top());
        //     front.pop();
        //     front.push(s);
        // }
        front.push(s);
    }
    string isWatching() const{
        return front.top(); 
    }
    string pred(){
        if (front.size() == 1) return "无法往前了！";
        
        back.push(front.top());
        front.pop();
        return front.top();
    }
    string next() {
        if (back.empty()) return "无法往后了";
        front.push(back.top());
        back.pop();
        return front.top();
    }
private:
    stack<string> front, back;
};
int main() {
    //  模拟浏览器的前进和后退
    // 思路就是两个栈相互倒
    history a;
    a.isWatching("baidu");
    // cout << a.isWatching() << endl;
    a.isWatching("google");
    a.isWatching("aaaaaaa");
    a.isWatching("bbbbbb");
    // cout << a.isWatching() << endl;
    cout << a.pred() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
    // cout << a.pred() << endl;
    // cout << a.pred() << endl;
    // cout << a.pred() << endl;
    // cout << a.pred() << endl;
    return 0;
}