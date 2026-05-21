class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n2 = arr2.size();
        unordered_set<int> st;
        for (int i = 0; i < n2; i++) {
            int number = arr2[i];
            while (number) {
                st.insert(number);
                number = number / 10;
            }
        }
        long long maxi = 0;
        int n1 = arr1.size();
        for (int i = 0; i < n1; i++) {
            int number = arr1[i];
            long long digits = 0;
            int dup = number;
            while (dup) {
                digits++;
                dup = dup / 10;
            }
            dup = number;
            while (dup) {
                if (st.find(dup) != st.end()) {
                    maxi = max(maxi, digits);
                    break;
                }
                dup = dup / 10;
                digits--;
            }
        }
        return maxi;
    }
};
