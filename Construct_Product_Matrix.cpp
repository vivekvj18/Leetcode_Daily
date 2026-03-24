class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int n = row * col;
        int m = 12345;
        vector<int> elements;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                elements.push_back(grid[i][j]);
            }
        }
        vector<int> left(n);
        long long product = 1;
        left[0] = 1;
        for (int i = 1; i < n; i++) {
            product = (product * elements[i - 1]) % m;
            left[i] = product;
        }
        vector<int> right(n);
        product = 1;
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            product = (product * elements[i + 1]) % m;
            right[i] = product;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = (left[i] * right[i]) % m;
        }
        vector<vector<int>> result(row, vector<int>(col));
        int idx = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[i][j] = ans[idx++];
            }
        }
        return result;
    }
};
