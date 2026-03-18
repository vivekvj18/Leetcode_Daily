class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> newmatrix(row, vector<int>(col, 0));
        int sum = 0;
        for (int i = 0; i < col; i++) {
            sum += grid[0][i];
            newmatrix[0][i] = sum;
        }
        sum = 0;
        for (int i = 0; i < row; i++) {
            sum += grid[i][0];
            newmatrix[i][0] = sum;
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                int value =
                    (grid[i][j] + newmatrix[i - 1][j] + newmatrix[i][j - 1]) -
                    newmatrix[i - 1][j - 1];
                newmatrix[i][j] = value;
            }
        }
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (newmatrix[i][j] <= k) {
                    ans++;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
