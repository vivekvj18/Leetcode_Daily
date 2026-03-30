class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> s1e(26, 0);
        vector<int> s1o(26, 0);
        vector<int> s2e(26, 0);
        vector<int> s2o(26, 0);
        for (int i = 0; i < n1; i++) {
            int idx = s1[i] - 'a';
            if (i % 2) {
                s1o[idx]++;
            } else {
                s1e[idx]++;
            }
        }
        for (int i = 0; i < n2; i++) {
            int idx = s2[i] - 'a';
            if (i % 2) {
                s2o[idx]++;
            } else {
                s2e[idx]++;
            }
        }
        return ((s1o==s2o) && (s1e==s2e));
    }
};
