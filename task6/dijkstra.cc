#include <iostream>
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

int main()
{
    return 0;
}