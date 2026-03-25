class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        unsigned long long totalsum = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                totalsum += grid[i][j];
            }
        }
        unsigned long long rowsum = 0;
        for (int i = 0; i < row-1; i++) {
            for (int j = 0; j < col; j++) {
                rowsum += grid[i][j];
            }
            if ((totalsum - rowsum) == rowsum) {
                return true;
            }
        }
        unsigned long long colsum = 0;
        for (int j = 0; j < col-1; j++) {
            for (int i = 0; i < row; i++) {
                colsum += grid[i][j];
            }

            if ((totalsum - colsum) == colsum) {
                return true;
            }
        }
        return false;
    }
};
