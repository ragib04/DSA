class Solution {
public:

int helper(int i, string &s, long long num, int sign, int n){
    if(i>=n || !isdigit(s[i])){
        return (int)(sign*num);
    }
    int digit = s[i] - '0';
    if(num>(INT_MAX-digit)/10) return (sign == 1)? INT_MAX: INT_MIN;
    return helper(i+1, s, num*10+digit, sign, n);
}
    int myAtoi(string s) {
        int n = s.size();
        long long num = 0;
        int i = 0;
        int sign = 1;
        while(i<n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {

            sign = (s[i] == '+')? 1: -1;
            i++;
        }
       
       
        return helper(i, s, 0, sign, n);
    }
};