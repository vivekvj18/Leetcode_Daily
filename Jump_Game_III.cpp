class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<int> idx(n, 0);
        q.push(start);
        idx[start] = 1;
        while (!q.empty()) {
            int val = q.front();
            q.pop();
            if (arr[val] == 0) {
                return true;
            }
            int val1 = val + arr[val];
            int val2 = val - arr[val];
            if (val1 >= 0 && val1 < n && idx[val1] == 0) {
                idx[val1] = 1;
                q.push(val1);
            }
            if (val2 >= 0 && val2 < n && idx[val2] == 0) {
                idx[val2] = 1;
                q.push(val2);
            }
        }
        return false;
    }
};
