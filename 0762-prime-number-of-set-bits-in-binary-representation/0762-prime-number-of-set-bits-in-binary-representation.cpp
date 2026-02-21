class Solution {
public:

bool isprime(int n){
    if(n<2) return false;
    for(int i = 2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}
bool helper(int n){
    int cnt = 0;
    while(n>0){
        n = n&(n-1);
        cnt++;

    }
    return isprime(cnt);
}
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i<=right; i++){
            if(helper(i)) ans++;
        }
        return ans;
    }
};