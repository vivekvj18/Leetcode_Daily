class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int mini=1e9;
        for(int i=0;i<n;i++)
        {
            if(words[(startIndex+i)%n]==target)
            {
                mini=min(mini,i);
            }
            if(words[(startIndex-i+n)%n]==target)
            {
                mini=min(mini,i);
            }
        }
        return (mini==1e9)?-1:mini;
    }
};
