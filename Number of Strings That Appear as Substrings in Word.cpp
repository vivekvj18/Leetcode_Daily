class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();
        unordered_set<string> st;
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = i; j < n; j++) {
                temp += word[j];
                st.insert(temp);
            }
        }
        int count = 0;
        for (int i = 0; i < patterns.size(); i++) {
            if (st.find(patterns[i]) != st.end()) {
                count++;
            }
        }
        return count;
    }
};
