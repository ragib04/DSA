class Solution {
  public:
    bool isPalindrome(int n) {
        // code here.
        long revnum = 0;
        int dup = n;
        while(n){
            int ld = n%10;
            if(revnum>INT_MAX/10 || revnum<INT_MIN/10) return 0;
            revnum = (revnum*10)+ld;
            n /= 10;
        }
        if(revnum == dup) return true;
        return false;
    }
};