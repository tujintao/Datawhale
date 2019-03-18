class Solution {
public:
    void dfs(int y, int n){
        if (y == n) {
            ans.push_back(board);
            return;
        }
        for (int x = 0; x < n; ++x) {
            if (cols[x] || diag[x + y] || anti_diag[x - y + n - 1] )continue;
            cols[x] = 1;
            diag[x + y] = 1;
            //反对角线原本的范围是 -(n-1) ~ (n - 1)  加上 x - y + n - 1 范围变成 0 ~ 2n - 1
            anti_diag[x - y + n - 1] = 1;
            board[x][y] = 'Q';
            dfs(y+1, n);
            cols[x] = 0;
            diag[x + y] = 0;
            anti_diag[x - y + n - 1] = 0;
            board[x][y] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        cols = vector<int>(n, 0);
        diag = vector<int>(2 * n, 0);
        anti_diag = vector<int>(2 * n, 0);
        dfs(0, n);
        return ans;
    }
private:
    vector<int> cols, diag, anti_diag;
    vector<string> board;
    vector<vector<string>> ans;
};
