class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> small(26, 0);
        vector<int> large(26, 0);
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (ch >= 'a' && ch <= 'z') {
                small[ch - 'a']++;
            } else {
                large[ch - 'A']++;
            }
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (small[i] != 0 && large[i] != 0) {
                count++;
            }
        }
        return count;
    }
};
