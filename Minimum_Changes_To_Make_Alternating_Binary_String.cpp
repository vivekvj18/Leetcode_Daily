class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ans1=0,ans2=0;
        for (int i = 0; i < n; i++) {
            char char1expected = (i % 2 == 0) ? '0' : '1';
            char char2expected = (i % 2 == 0) ? '1' : '0';
            if (s[i] != char1expected) {
                ans1++;
            }
            if (s[i] != char2expected) {
                ans2++;
            }
        }
        return min(ans1, ans2);
    }
};
