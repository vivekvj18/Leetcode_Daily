class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ansrow = m - k + 1;
        int anscol = n - k + 1;
        vector<vector<int>> ans(ansrow, vector<int>(anscol, 0));
        for (int i = 0; i < ansrow; i++) {
            for (int j = 0; j < anscol; j++) {
                unordered_set<int> st;
                for (int b = i; b < i + k; b++) {
                    for (int c = j; c < j + k; c++) {
                        st.insert(grid[b][c]);
                    }
                }
                vector<int> elements;
                for (auto it : st) {
                    elements.push_back(it);
                }
                sort(elements.begin(), elements.end());
                int mini = INT_MAX;
                for (int i = 0; i < elements.size() - 1; i++) {
                    int diff = abs(elements[i] - elements[i + 1]);
                    mini = min(mini, diff);
                }
                ans[i][j] = (mini != INT_MAX) ? mini : 0;
            }
        }
        return ans;
    }
};
