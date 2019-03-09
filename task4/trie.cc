#include <iostream>
#include <memory>
#include <vector>
using namespace std;
struct node{
    node():is_word(false), children(26, nullptr){}
    ~node(){
        for (node* child : children)
            if (child) delete child;
    }
    bool is_word;
    int count;
    vector<node*> children;
};
class trie{
public:
    trie(): root(new node()){
    }
    void insert(const string& word){
        node* p = root.get();
        for (const char c : word) {
            if (!p->children[c - 'a'])
                p->children[c - 'a'] = new node();
            p = p->children[c - 'a'];
        }
        p->is_word = true;
    }
    const node* find(const string& prefix) const {
        const node* p = root.get();
        for (const char c : prefix) {
            p = p->children[c - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }
private:
    unique_ptr<node> root;
};
int main()
{
    trie a;
    vector<string> test = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    for (string word : test) {
        a.insert(word);
    }
    cout << (a.find("the") == nullptr) << endl;
    cout << (a.find("none") == nullptr) << endl;
    return 0;
}