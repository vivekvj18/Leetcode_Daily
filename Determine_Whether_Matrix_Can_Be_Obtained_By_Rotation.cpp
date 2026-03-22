class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row = mat.size();
        int col = mat[0].size();
        if(mat==target)return true;
        vector<vector<int>> temp(row,vector<int>(row));
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    temp[j][row - i - 1]=mat[i][j];
                }
            }
            mat=temp;
            if (temp == target) {
                return true;
            }
        }
        return false;
    }
};
