class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int number = nums[i];
            vector<int> temp;
            while (number) {
                temp.push_back(number % 10);
                number = number / 10;
            }
            reverse(temp.begin(), temp.end());
            for (int j = 0; j < temp.size(); j++) {
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};
