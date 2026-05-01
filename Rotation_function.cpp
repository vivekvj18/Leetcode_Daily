class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int prev= 0;
        for(int i=0;i<n;i++)
        {
            sum = sum+nums[i];
            prev = prev + (i*nums[i]);
        }
        int maxi = prev;
        for(int i=1;i<n;i++)
        {
            int total = prev + (sum -n*nums[n-i]);
            maxi = max(maxi,total);
            prev = total; 
        }
        return maxi;
    }
};
