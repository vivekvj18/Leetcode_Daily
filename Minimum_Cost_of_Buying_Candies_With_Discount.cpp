class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int sum = 0;
        sort(cost.begin(), cost.end());
        if (n == 1) {
            return cost[0];
        }
        if (n == 2) {
            return cost[0] + cost[1];
        }
        int l = 1;
        for (int i = n - 1; i >= 0; i--) {
            if ((l % 3) == 0) {
                l++;
                continue;
            }
            sum += cost[i];
            l++;
        }
        return sum;
    }
};
