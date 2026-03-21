class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int start = x;
        int end = x + k - 1;
        while (start < end) {
            for (int j = y; j < y + k; j++) {
                if (start < row && end < row && j < col) {
                    swap(grid[start][j], grid[end][j]);
                }
            }
            start++;
            end--;
        }
        return grid;
    }
};
