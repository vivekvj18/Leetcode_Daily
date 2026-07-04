class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> visited(n, 0);
        queue<int> q;
        for (auto it : roads) {
            adj[it[0] - 1].push_back({it[1] - 1, it[2]});
            adj[it[1] - 1].push_back({it[0] - 1, it[2]});
        }
        q.push(0);
        visited[0] = 1;
        int ans = 1e9;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                int adjnode = it.first;
                int edgeweight = it.second;
                ans = min(ans, edgeweight);
                if (!visited[adjnode]) {
                    visited[adjnode] = 1;
                    q.push(adjnode);
                }
            }
        }
        return ans;
    }
};
