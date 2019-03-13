class Solution {
public:
    void dfs(vector<vector<char>>& g, int x, int y) {
        // if (g[x][y] == '0') return;
        if (x < 0 || x >= r || y < 0 || y >= c) return;
        // cout << "s";
        for (int i = 0; i < 4; ++i) {
            int nx = dir[i][0] + x;
            int ny = dir[i][1] + y;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (g[nx][ny] == '0') continue;
            g[nx][ny] = '0';
            dfs(g, nx, ny);
        }
    }
    void print(vector<vector<char>>& g) {
        for (auto i : g) {
            for (auto e : i) {
                cout << e << " ";
            }
            cout << endl;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        if (r == 0) return 0;
        c = grid[0].size();
        cnt = 0;
        queue<pair<int,int>> que;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == '1') {
                    que.push({i, j});
                    grid[i][j] = '0';
                    while (que.size()) {
                        auto t = que.front();
                        que.pop();
                        for (int i = 0; i < 4; ++i) {
                            int nx = t.first + dir[i][0];
                            int ny = t.second + dir[i][1];
                            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                                continue;
                            if (grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                que.push({nx, ny});
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        // print(grid);
        return cnt;
    }
private:
    int cnt;
    int dir[4][2] = {0,-1, 0, 1, 1, 0, -1, 0};
    int r, c;
};