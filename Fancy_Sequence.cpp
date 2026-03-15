class Fancy {
public:
    vector<long long> vpp;
    int M = 1e9 + 7;
    long long add=0;
    long long mul=1;

    long long power(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half   = power(a, b/2);
        long long result = (half * half) % M;

        if(b%2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    Fancy() {}

    void append(int val) { 
        long long x = (((val - add) % M + M) % M * power(mul, M-2) % M);
        vpp.push_back(x);
     }

    void addAll(int inc) {
        add=(add+inc)%M;
    }

    void multAll(int m) {
        mul=(mul*m)%M;
        add=(add*m)%M;
        
    }

    int getIndex(int idx) {
        int n = vpp.size();
        if (idx >= n) {
            return -1;
        }
        return ((vpp[idx]*mul)+add)%M;
        
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
