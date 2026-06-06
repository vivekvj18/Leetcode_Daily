class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n, 0);
        vector<int> rightsum(n, 0);
        int lsum = 0;
        int rsum = 0;
        for (int i = 0; i < n; i++) {
            leftsum[i] = lsum;
            lsum += nums[i];
            rightsum[n - i - 1] = rsum;
            rsum += nums[n - i - 1];
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = abs(leftsum[i] - rightsum[i]);
        }
        return ans;
    }
};
