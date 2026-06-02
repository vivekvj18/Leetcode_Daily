class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n1 = landStartTime.size();
        int n2 = waterStartTime.size();
        int mini = INT_MAX;
        for (int i = 0; i < n1; i++) {
            int landtime = landStartTime[i] + landDuration[i];
            for (int j = 0; j < n2; j++) {
                int totaltime = 0;
                if (waterStartTime[j] <= landtime) {
                    totaltime = landtime + waterDuration[j];
                } else {
                    totaltime = waterStartTime[j] + waterDuration[j];
                }
                mini = min(mini, totaltime);
            }
        }
        for (int i = 0; i < n2; i++) {
            int watertime = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < n1; j++) {
                int totaltime = 0;
                if (landStartTime[j] <= watertime) {
                    totaltime = watertime + landDuration[j];
                } else {
                    totaltime = landStartTime[j] + landDuration[j];
                }
                mini = min(mini, totaltime);
            }
        }
        return mini;
    }
};
