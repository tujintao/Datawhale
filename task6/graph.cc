#include <iostream>
#include <vector>
using namespace std;
//邻接矩阵
// G[N][N]; 
// u v w 代表前驱后继和权值
// G[u][v] = w 表示 u->v 建立一条边表示有向图 无权图w可任意
// G[u][v] = w; G[v][u] = w 无向图的话 还需要反向建边
// 邻接表
// 参考了邓俊辉的数据结构 部分实现
struct Edge { //定义边的信息
    int dest;
    int cost;
    Edge *next;//图的关系太复杂了 老老实实用裸指针了
    Edge(){}
    Edge(int num, int weight):dest(num), cost(weight), next(nullptr){}
    bool operator != (Edge& r) const {
        return (dest != r.dest) ? true : false;
    }
};
struct Vertex{
    int data;
    Edge *adj;//邻接表的头指针
};
class Graph{
public:
    Graph(int sz=30){
        maxVertices = sz;
        numVertices = 0;
        numEdges = 0;
        nodeTable = new Vertex[maxVertices];
        for (int i = 0; i < maxVertices; ++i) {
            nodeTable[i].adj = nullptr;
        }
    }

    ~Graph(){
        for (int i = 0; i < numVertices; ++i) {
            Edge *p = nodeTable[i].adj;
            while (p) {
                nodeTable[i].adj = p->next;
                delete p;
                p = nodeTable[i].adj;
            }
        }
        delete [] nodeTable;
    };
    int getValue(int i) {
        return (i > 0 && i <= numVertices) ? nodeTable[i].data : 0;
    }

    bool insertVectex(const int& v){
        if (numVertices == maxVertices) return false;
        nodeTable[numVertices].data = v;
        numVertices++;
        return true;
    }

    int getWeight(int u, int v){
        if (u != -1 && v != -1) {
            Edge *p = nodeTable[u].adj;
            while(p != nullptr && p->dest != v)
                p = p->next;
            if (p != nullptr) return p->cost; 
        }
        cerr << "节点不存在" << endl;
        exit(-1);
    }
    bool isValid(int vertex){return (vertex > 0 && vertex <= numVertices);}
    
    bool addEdge(int u, int v, int cost) {
        if (isValid(u) && isValid(v)) {
            Edge *q, *p = nodeTable[u].adj;

            while(p != nullptr && p->dest != v)
                p = p->next;
            //判断是否是重边
            if (p != nullptr) {
                cerr << "插入失败！"<< endl;
                return false;
            }
            p = new Edge;
            q = new Edge;
            p->dest = v;
            p->cost = cost;
            p->next = nodeTable[u].adj;
            nodeTable[u].adj = p;
            //比如说有五条边 (u,v) (1, 2) (1,3) (1, 4) (3, 5) 
// nodeTable[u]    v
            //1 -> 2 -> 3
            //2 -> null
            //3 -> 5
            //4 -> null
            //5 -> null
            //这就实现了有向图的邻接表 无向图的话在(v, u)插入一次即可
            // q->dest = u;
            // q->cost = cost;
            // q->next = nodeTable[v].adj;
            // nodeTable[v].adj = q;
            numEdges++;
            return true;
        }
        return false;
    }

    bool deleteEdge(int u, int v) {
        if (isValid(u) && isValid(v)) {
            Edge *p = nodeTable[u].adj, *q = nullptr, *head = p;
            while (p != nullptr && p->dest != v) {
                q = p;
                p = p->next;
            }
            if (p != nullptr) {
                //只有一个节点
                if (p == head) nodeTable[u].adj = p->next;
                else q->next = p->next;

            } else return false;
            return false;
        }
    }
    void input(){
        int m, n;
        int u, v, cost;
        //顶点个数 边数
        // 3 3
        // 1 2 3
        // 1 3 1
        // 3 2 4
        // cin >> n >> m;
        //for (int i = 1; i <= n; ++i) insertVectex(i);
        // for (int i = 0; i < n; ++i) {
        //     cin >> u >> v >> cost;
        //     addEdge(u, v, cost);
        //     // addEdge(v, u, cost);
        // }
        n = 3, m = 3;
        for (int i = 1; i <= n; ++i) insertVectex(i);
        addEdge(1, 2, 3);
        addEdge(1, 3, 1);
        addEdge(3, 2, 4);
        deleteEdge(3, 2);
    }
    void print(){
        for (int i = 1; i <= numVertices; ++i) {
            if (nodeTable[i].adj != nullptr){
                Edge *p = nodeTable[i].adj;
                while (p) {
                    cout << "u:" << i << " " << "v:" << p->dest << " " << "cost:" << p->cost << endl;
                    p = p->next;
                }
            }
        }
    }
private:
    Vertex *nodeTable; //顶点表
    int maxVertices;
	int numEdges;
	int numVertices;
};

int main()
{
    Graph test;
    test.input();
    test.print();
    return 0;
}