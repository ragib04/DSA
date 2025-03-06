class Solution {
public:
//recursive app--------->>>>>>>

int solve(int n, int p){
    if(n==0) return true;
    if(pow(3,p)>n) return false;

    bool p_pick = solve(n-pow(3,p), p+1);
    bool p_notpick = solve(n, p+1);

    return p_pick || p_notpick;
}
    bool checkPowersOfThree(int n) {
        return solve(n,0);
    }
    /*
      bool checkPowersOfThree(int n) {
       for(int i = 16; i>=0; i--){
        int power = pow(3,i);
        if(n>power) n-= power;
        else if(n==power) return true;
       }
        return false;
    }
    */
};