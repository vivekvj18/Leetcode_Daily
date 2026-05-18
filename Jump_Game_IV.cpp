class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> visited(n, 0);
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        int jumps = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1) {
                    return jumps;
                }

                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = 1;
                    q.push(curr - 1);
                }

                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = 1;
                    q.push(curr + 1);
                }

                for (auto idx : mp[arr[curr]]) {
                    if (!visited[idx]) {
                        visited[idx] = 1;
                        q.push(idx);
                    }
                }

                mp[arr[curr]].clear();
            }

            jumps++;
        }

        return -1;
    }
};
