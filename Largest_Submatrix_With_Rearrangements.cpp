class Solution {
public:

    static bool cmp(int a, int b) { return a > b; }

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ones(row, vector<int>(col, 0));
        for (int j = 0; j < col; j++) {
            int count = 0;
            for (int i = 0; i < row; i++) {
                if (matrix[i][j] == 1) {
                    count++;
                    ones[i][j] = count;
                } else {
                    count = 0;
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < row; i++) {
            sort(ones[i].begin(), ones[i].end(), cmp);
            for (int j = 0; j < col; j++) {
                int area = (j + 1) * ones[i][j];
                maxi = max(maxi, area);
            }
        }
        return maxi;
    }
};
