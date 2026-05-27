class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> small(26, 0);
        vector<int> large(26, 0);
        vector<int> count(26, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                int ch = word[i] - 'a';
                if (large[ch] != 0) {
                    count[ch] = 0;
                }
                small[ch]++;
            } else if (word[i] >= 'A' && word[i] <= 'Z') {
                int ch = word[i] - 'A';
                if (large[ch] == 0 && small[ch] != 0) {
                    count[ch]++;
                }
                large[ch]++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                ans++;
            }
        }
        return ans;
    }
};
