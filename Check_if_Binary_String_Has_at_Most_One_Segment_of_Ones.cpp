class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        if (n == 1) {
            return true;
        }
        int times = 1;
        for (int i = 1; i < n; i++) {
            if (times == 1 && s[i] == '1' && s[i - 1] == '1') {
                continue;
            }
            if (times == 1 && s[i] == '1' && s[i - 1] != '1') {
                return false;
            }
        }
        return true;
    }
};
