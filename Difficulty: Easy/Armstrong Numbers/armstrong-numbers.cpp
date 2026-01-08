// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int dup = n;
        int sum = 0;
        while(n){
            int ld = n%10;
            sum += (ld*ld*ld);
            n /= 10;
        }
        if(sum == dup) return true;
        return false;
        
    }
};