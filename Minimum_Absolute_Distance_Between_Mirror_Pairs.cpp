class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int mini=1e9;
        for(int i=n-1;i>=0;i--)
        {
            int value = nums[i];
            string str = to_string(value);
            reverse(str.begin(),str.end());
            int rev = stoi(str);
            if(mpp.find(rev)!=mpp.end())
            {
                mini=min(mini,mpp[rev]-i);
            }
            mpp[nums[i]]=i;
        }
        return (mini==1e9)?-1:mini;
    }
};
