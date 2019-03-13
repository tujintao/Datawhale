#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//对一个有向无环图拓扑排序0
//用一个队列实现，先把入度为0的点放入队列。然后考虑不断在途中删除队列的点。
//每次删除一个点会产生一些新的入度为0的点。把这些点插入
//用vector实现邻接表
//复杂度 O(V + E) 
const int maxn = 1e5+7;
vector<int> g[maxn];
int du[maxn], n, m, ans[maxn],tot;
bool toposort() {

    memset(du, 0, sizeof(du));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < g[i].size(); ++j)
            du[g[i][j]]++;

    tot = 0;
    queue<int> que;
    for (int i = 0; i < n; ++i)
        if (!du[i])que.push(i);

    while (que.size()) {
        int u = que.front();
        que.pop();
        ans[tot++] = u;
        for (int j = 0; j < g[u].size(); ++j) {
            int t = g[u][j];
            du[t]--;
            if (!du[t])
                que.push(t);
        }
    }

    return tot == n ? true : false;
}
int main()
{
    // 3 3
    // 1 2
    // 2 3
    // 1 3
    freopen("in","r", stdin);
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i){
        cin >> u >> v;
        g[u].push_back(v);
    }
    toposort();
    for (int i = 1; i < tot; ++i)
        cout << ans[i];
    return 0;
}