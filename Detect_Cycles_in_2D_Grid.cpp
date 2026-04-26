class Solution {
    vector<int> xc = {0, -1, 0, 1};
    vector<int> yc = {1, 0, -1, 0};

private:
    bool dfs(int x, int y, int px, int py, int row, int col,
             vector<vector<int>>& visited, vector<vector<char>>& grid) {
        visited[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int newxc = x + xc[i];
            int newyc = y + yc[i];
            if (newxc >= 0 && newyc >= 0 && newxc < row && newyc < col &&
                grid[x][y] == grid[newxc][newyc]) {
                if (visited[newxc][newyc] == 1) {
                    if (newxc != px || newyc != py) {
                        return true;
                    }
                } else {
                    if (dfs(newxc, newyc, x, y, row, col, visited,
                            grid)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (visited[i][j] == 0) {
                    if (dfs(i, j, -1, -1, row, col, visited, grid)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
