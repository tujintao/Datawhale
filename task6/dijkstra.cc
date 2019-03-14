#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
//参考挑战程序设计竞赛
const int maxn = 1e5;
int cost[maxn][maxn];//cost[u][v]表示边e=(u, v)的权值 不存在初始化为INF
int d[maxn]; //顶点s出发的最短距离
bool used[maxn];//已经使用过的图
int V;//顶点数
const int INF = 0x3f3f3f3f;
void dijkstra(int s){
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;
    while(true) {
        int v = -1;
        //从未使用过的顶点中选择一个距离最小的顶点
        for (int u = 0; u < V; ++u) {
            if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if (v == -1) break;
        used[v] = true;
        for (int u = 0; u < V; ++u){
            if (d[u] > d[v] + cost[u][v]) {
                d[u] = d[v] + cost[v][u];
            }
        }
    }
} 
//用堆优化查找下一个使用的顶点的最短距离
struct edge{
    int to, cost;
};
typedef pair<int, int> P;//first 最短距离 second是
vector<edge> G[maxn];
int d2[maxn];
void dijkstra2(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d2, d2 + V, INF);
    d2[s] = 0;
    que.push(P(0, s));
    while (que.size()) {
        P p = que.top();
        que.pop();
        int u = p.second;
        //当前不是最短距离的话
        //也就是说u没有被访问过
        if (d2[u] < p.first) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            edge v = G[u][i];//前驱u 后继v
            if (d2[v.to] > d2[u] + d2[v.cost]){
                d2[v.to] = d2[u] + v.cost;
                que.push(P(d[v.to], v.to));
            }
        }
    }
}
int main()
{
    return 0;
}