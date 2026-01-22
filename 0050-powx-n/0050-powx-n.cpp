class Solution {
public:

double calcu(double x, long n){
    if(n == 0) return 1.00;
    double half = calcu(x, n/2);
     
     if(n%2 == 0) return half*half;
     else return half*half*x;
}
    double myPow(double x, int n) {
        
        long nn = n;
        if(nn<0){
            x = 1/x;
            nn = -nn;
        }
       return calcu(x, n);
        
    }
};