class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int noofbits=floor(log2(n))+1;
        int value=pow(2,noofbits)-1;
        int ans=value-n;
        return ans;
    }
};
