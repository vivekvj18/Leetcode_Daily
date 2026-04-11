class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        int mini = 1e9;
        for (auto it : mpp) {
            if (it.second.size() >= 3) {
                for (int i = 0; i <= it.second.size() - 3; i++) {
                    int ans = abs(it.second[i] - it.second[i + 1]) +
                              abs(it.second[i + 1] - it.second[i + 2]) +
                              abs(it.second[i + 2] - it.second[i]);
                    mini = min(mini, ans);
                }
            }
        }
        return (mini == 1e9) ? -1 : mini;
    }
};
