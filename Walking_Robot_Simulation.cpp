class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for (vector<int>& obj : obstacles) {
            string key = to_string(obj[0]) + " " + to_string(obj[1]);
            st.insert(key);
        }
        int x = 0;
        int y = 0;
        int maxdist = 0;
        pair<int, int> dir = {0, 1};

        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2) {
                dir = {-dir.second, dir.first};
            } else if (commands[i] == -1) {
                dir = {dir.second, -dir.first};
            } else {
                for (int step = 0; step < commands[i]; step++) {
                    int newx = x + dir.first;
                    int newy = y + dir.second;

                    string next_key = to_string(newx) + " " + to_string(newy);
                    if (st.find(next_key) != st.end()) {
                        break;
                    }
                    x = newx;
                    y = newy;
                }
            }
            maxdist = max(maxdist, (x * x) + (y * y));
        }
        return maxdist;
    }
};
