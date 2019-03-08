#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRU {
public:
    LRU (int c) {
        _capacity = c;
    }
    //使用当前数据
    int get (int key) {
        const auto it = _m.find(key);
        //不存在的话
        if (it == _m.cend()) return -1;
        //把结点移动到cache的最前面
        _cache.splice(_cache.begin(), _cache, it->second);
        //返回key 所对应的val
        return it->second->second;
    }
    //新的数据进来
    void put (int key, int value) {
        const auto it = _m.find(key);
        //如果key 存在
        //更新val值
        if (it != _m.cend()) {
            it->second->second = value;
            _cache.splice(_cache.begin(), _cache, it->second);
            return;
        }
        // key不存在的时候
        // cache满了 我们要删除掉最右边的元素 保证有合适的空间
        if (_cache.size() == _capacity) {
            const auto& node = _cache.back();
            _m.erase(node.first);
            _cache.pop_back();
        }
        //插入到最前边
        _cache.emplace_front(key, value);
        _m[key] = _cache.begin();

    }
private:
    int _capacity;
    list<pair<int,int> > _cache;//存放(key, val)
    //为了高效的查找到key使用hashmap val存放当前key对应的_cache中的迭代器
    unordered_map<int, list<pair<int,int> > :: iterator> _m;
};
int main()
{
    LRU cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;      
    cache.put(3, 3);   
    cout << cache.get(2) << endl;       
    cache.put(4, 4);    
    cout << cache.get(1) << endl;   
    cout << cache.get(3) << endl; 
    cout << cache.get(4) << endl; 
    return 0;
}