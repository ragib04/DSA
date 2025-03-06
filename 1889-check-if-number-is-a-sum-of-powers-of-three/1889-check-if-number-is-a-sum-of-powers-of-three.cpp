class Solution {
public:
    bool checkPowersOfThree(int n) {
       for(int i = 16; i>=0; i--){
        int power = pow(3,i);
        if(n>power) n-= power;
        else if(n==power) return true;
       }
        return false;
    }
};