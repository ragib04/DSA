class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        //applying AND operation firstly   /covert in Binary form the apply and if is 0 return true
        return (n&(n-1)) == 0;    
    }
};