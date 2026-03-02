//1536. Minimum Swaps to Arrange a Binary Grid
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> zerocount(row, 0);
        for (int i = 0; i < row; i++) {
            long long freqzero = 0;
            int j = col - 1;
            while (j >= 0 && grid[i][j] != 1) {
                freqzero++;
                j--;
            }
            zerocount[i] = freqzero;
        }
        int swaps = 0;
        for (int i = 0; i < row; i++) {
            int needofrow = row - i - 1;
            bool flag = false;
            for (int j = i; j < row; j++) {
                if (zerocount[j] >= needofrow) {
                    int noofswaps = (j - i);
                    swaps += noofswaps;
                    int index = j;
                    for (int k = 0; k < noofswaps; k++) {
                        swap(zerocount[index], zerocount[index - 1]);
                        index--;
                    }
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                return -1;
            }
        }
        return swaps;
    }
};
