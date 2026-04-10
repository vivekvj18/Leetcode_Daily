class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int mini = 1e9;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = i + 1; j <= n - 2; j++) {
                for (int k = j + 1; k <= n - 1; k++) {
                    if ((nums[i] == nums[j]) && (nums[j] == nums[k])) {
                        int ans = abs(i - j) + abs(j - k) + abs(k - i);
                        mini = min(mini, ans);
                    }
                }
            }
        }
        return (mini==1e9)?-1:mini;
    }
};
