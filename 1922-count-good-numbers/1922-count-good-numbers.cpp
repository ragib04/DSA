class Solution {
public:
const int mod = 1e9+7;
long long findpow(long long x, long long n){
    if(n == 0) return 1;
    long long half = findpow(x, n/2);
    long long res = (half*half)%mod;
    if(n%2 == 1) return (res*x)%mod;
    return res;
}
    int countGoodNumbers(long long n) {
       
        long long ans = (findpow(5, (n+1)/2) * findpow(4,n/2))%mod;
        return (int)ans;
    }
};