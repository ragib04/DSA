class Solution {
public:

double calcu(double x, long n){
    if(n == 0) return 1.00;
     
     if(n%2 == 0) return calcu(x*x, n/2);
     return x * calcu(x*x, (n-1)/2);
}
    double myPow(double x, int n) {
        
        long nn = n;
        if(nn<0){
            x = 1/x;
            nn = -nn;
        }
       return calcu(x, nn);
        
    }
};