class Solution {
    int M=1e9+7;
    private:
    int solve(int zeroleft,int oneleft,int limit,bool lastwasone,int dp[201][201][2])
    {
        if(zeroleft==0 && oneleft==0)
        {
            return 1;
        }
        if(dp[zeroleft][oneleft][lastwasone]!=-1)
        {
            return dp[zeroleft][oneleft][lastwasone];
        }
        int result=0;
        if(lastwasone==true)
        {
            for(int length=1;length<=min(limit,zeroleft);length++)
            {
                result = (result+solve(zeroleft-length,oneleft,limit,false,dp))%M;
            }
        }
        else
        {
            for(int length=1;length<=min(limit,oneleft);length++)
            {
                result = (result+solve(zeroleft,oneleft-length,limit,true,dp))%M;
            }
        }
        return dp[zeroleft][oneleft][lastwasone]=result;
    }
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[201][201][2];
        memset(dp,-1,sizeof(dp));
        long long ans1=solve(zero,one,limit,true,dp);
        long long ans2=solve(zero,one,limit,false,dp);
        return (ans1+ans2)%M;
    }
};
