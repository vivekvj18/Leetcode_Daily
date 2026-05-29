class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1e9;
        for (int i = 0; i < n; i++) {
            int number = nums[i];
            int sum = 0;
            while (number) {
                sum += number % 10;
                number = number / 10;
            }
            maxi = min(maxi, sum);
        }
        return maxi;
    }
};
