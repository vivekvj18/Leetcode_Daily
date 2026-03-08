class Solution {
    string ans = "";
    void find(int index, int n, string curr, unordered_set<string>& st) {
        if (index == n) {
            if (st.find(curr) == st.end()) {
                ans = curr;
            }
            return;
        }
        curr.push_back('0');
        find(index + 1, n, curr, st);
        curr.pop_back();
        if (ans != "") {
            return;
        }
        curr.push_back('1');
        find(index + 1, n, curr, st);
        curr.pop_back();
        return;
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        int size = nums.size();
        int n = nums[0].length();
        string curr = "";
        unordered_set<string> st;
        for (int i = 0; i < size; i++) {
            st.insert(nums[i]);
        }
        find(0, n, curr, st);
        return ans;
    }
};
