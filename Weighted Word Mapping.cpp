class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<char> freq(26);
        unordered_map<char, int> mpp;
        for (int i = 0; i < 26; i++) {
            freq[i] = 'z' - i;
        }
        for (int i = 0; i < 26; i++) {
            mpp['a' + i] = weights[i];
        }
        int m = words.size();
        int k = 0;
        string ans;
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < words[i].size(); j++) {
                char ch = words[i][j];
                sum += mpp[ch];
            }
            sum = sum % 26;
            cout << sum << " ";
            ans.push_back(freq[sum]);
        }
        return ans;
    }
};
