class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long revnum = 0;
        long dup = x;
        while(x){
            long ld = x%10;
            if((revnum > INT_MAX/10) || (revnum < INT_MIN/10)){
            return 0;
        }
            revnum = (revnum*10)+ld;
            x /= 10;
        }
        if(revnum != dup) return false;
        else return true;
    }
};