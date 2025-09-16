class Solution {
public:

int gcd(int a, int b){
    return b == 0? a: gcd(b, a%b);
}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(auto num: nums){
            while(!st.empty()){
                int top = st.back();
                int GCD = gcd(top, num);
                if(GCD == 1) break;
                st.pop_back();
                long long LCM = (long long)top/GCD*num;
                num = (int)LCM;
                
            }
            st.push_back(num);
        }
        return st;
    }
};