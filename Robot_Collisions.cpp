class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths,
                                      string directions) {
        int n = positions.size();

        vector<int> indx(n);
        for (int i = 0; i < n; i++) {
            indx[i] = i;
        }

        sort(indx.begin(), indx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st;

        for (int i = 0; i < n; i++) {
            int curr = indx[i];

            if (directions[curr] == 'R') {
                st.push(curr);
            } else {
                while (!st.empty() && healths[curr] > 0) {
                    int top_idx = st.top();
                    st.pop();

                    if (healths[top_idx] > healths[curr]) {
                        healths[top_idx] -= 1;
                        healths[curr] = 0;
                        st.push(top_idx);
                    } else if (healths[top_idx] < healths[curr]) {
                        healths[curr] -= 1;
                        healths[top_idx] = 0;
                    } else {
                        healths[top_idx] = 0;
                        healths[curr] = 0;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};
