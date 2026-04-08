class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n1 = nums.size();
        int n2 = queries.size();
        long long mod = 1e9 + 7;
        for (int i = 0; i < n2; i++) {
            int li = queries[i][0];
            int ri = queries[i][1];
            int ki = queries[i][2];
            int vi = queries[i][3];
            int idx = li;
            while (idx <= ri) {
                nums[idx] = ((long long)nums[idx] * vi) % mod;
                idx += ki;
            }
        }
        int ans = 0;
        for (int i = 0; i < n1; i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
