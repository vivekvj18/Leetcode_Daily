class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string t = s + s;
        int diff1 = 0;
        int diff2 = 0;
        int l = 0;
        int r = 0;
        int mini = INT_MAX;
        while (r < (2 * n)) {
            char char1 = (r % 2 == 0 ? '1' : '0');
            char char2 = (r % 2 == 0 ? '0' : '1');
            if (t[r] != char1) {
                diff1++;
            }
            if (t[r] != char2) {
                diff2++;
            }
            if (r - l + 1 > n) {
                char l1 = (l % 2 == 0 ? '1' : '0');
                char l2 = (l % 2 == 0 ? '0' : '1');
                if (t[l] != l1) {
                    diff1--;
                }
                if (t[l] != l2) {
                    diff2--;
                }
                l++;
            }
            if((r-l+1)==n)
            {
                mini=min(mini,min(diff1,diff2));
            }

            r++;
        }
        return mini;
    }
};
