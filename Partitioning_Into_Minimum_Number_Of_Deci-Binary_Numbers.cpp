//1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        int size=n.length();
        for(int i=0;i<size;i++)
        {
            int number=n[i]-'0';
            maxi=max(maxi,number);
        }
        return maxi;
    }
};
