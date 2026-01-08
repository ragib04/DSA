class Solution {
  public:
    bool isPerfect(int n) {
        // code here
        int sum = 1;
        for(int i = 2; i*i<=n; i++){
            if(n%i == 0){
                if(i*i != n){
                    sum += i+ n/i;
                }
                else sum += i;
            }
        }
        if(sum == n && n != 1) return true;
        return false;
        
    }
};