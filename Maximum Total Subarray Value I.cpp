class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        unsigned long long diff = maxi - mini;
        unsigned long long totalvalue = k * diff;
        return totalvalue;
    }
};
