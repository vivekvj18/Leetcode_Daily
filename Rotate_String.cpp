class Solution {
public:
    bool rotateString(string s, string goal) {
        int l1 = s.length();
        int l2 = goal.length();
        if(l1!=l2)return false;
        string n = s + s;
        for (int i = 0; i < n.length(); i++) {
            if (n[i] == goal[0]) {
                int j = i;
                int k = 0;
                while (n[j] == goal[k]) {
                    j++;
                    k++;
                }
                if (k == l2 && j <= n.length()) {
                    return true;
                }
            }
        }
        return false;
    }
};
