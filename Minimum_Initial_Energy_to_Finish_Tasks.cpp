class Solution {
private:
    bool ispossibleans(int mid, vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (auto it : tasks) {
            if (mid >= it[1] && mid >= it[0]) {
                mid = mid - it[0];
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), comp);
        int ans = 0;
        int start = 0;
        int end = 1e9;
        while (start <= end) {
            int mid = start+(end-start)/2;
            if (ispossibleans(mid, tasks)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
