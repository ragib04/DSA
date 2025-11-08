class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0) return 0;
        vector<int> f(31, 0);
        f[0] = 1;
        for(int i = 1; i<=30; i++){
            f[i] = 2*f[i-1]+1;
        }
        int sign = 1;
        int res = 0;
        for(int i = 30; i>=0; i--){
            int ith_bit = ((1<<i)&n);
            if(ith_bit == 0) continue;
            if(sign>0){
                res += f[i];

            }
            else res -= f[i];

            sign = sign*(-1);
        }
        return res;
    }
};