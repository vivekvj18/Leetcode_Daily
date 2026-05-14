class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return false;
        vector<int> vpp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                vpp[nums[i]]++;
            } else {
                return false;
            }
        }
        for (int i = 1; i < n; i++) {
            if (i != n-1 && vpp[i] != 1) {
                return false;
            }
            if (i == n-1 && vpp[i] != 2) {
                return false;
            }
        }
        return true;
    }
};
