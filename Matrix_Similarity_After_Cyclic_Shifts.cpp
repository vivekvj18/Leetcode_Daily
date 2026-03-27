class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int row=mat.size();
        int col=mat[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(mat[i][(j+k)%col]!=mat[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
