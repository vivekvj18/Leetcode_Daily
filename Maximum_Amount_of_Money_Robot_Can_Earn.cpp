class Solution {
private:
    int find(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp) {
        // base case
        if (i < 0 || j < 0) {
            return -1e9;
        }

        if (i == 0 && j == 0) {
            if (coins[i][j] >= 0) {
                return coins[i][j];
            } else {
                if (k > 0) {
                    return 0;
                } else {
                    return coins[i][j];
                }
            }
        }
        if(dp[i][j][k]!=INT_MIN)
        {
            return dp[i][j][k];
        }

        // compute
        int maxi = INT_MIN;
        int ans = INT_MIN;
        int ans2 = INT_MIN;
        int value = INT_MIN;
        if (coins[i][j] >= 0) {
            ans = coins[i][j] +
                  max(find(i - 1, j, k, coins,dp), find(i, j - 1, k, coins,dp));
        } else {
            int ans1 = coins[i][j] +
                       max(find(i - 1, j, k, coins,dp), find(i, j - 1, k, coins,dp));
            if (k > 0) {
                ans2 = 0+max(find(i - 1, j, k - 1, coins,dp),
                           find(i, j - 1, k - 1, coins,dp));
            }
            value = max(ans1, ans2);
        }

        return dp[i][j][k] = max(ans, value);

        // save and return
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return find(m - 1, n - 1, 2, coins,dp);
    }
};
