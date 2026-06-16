class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string ans;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans.push_back(s[i]);
                j++;
            } else if (s[i] == '*') {
                if (j > 0) {
                    if (ans.size()) {
                        ans.pop_back();
                    }
                }
            } else if (s[i] == '#') {
                ans = ans + ans;
            } else if (s[i] == '%') {
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }
};
