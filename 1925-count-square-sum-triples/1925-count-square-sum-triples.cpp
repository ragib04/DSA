class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
       unordered_set<int> st;
       for(int i = 1; i<=n; i++){
            st.insert(i*i);
       }
       for(int i = 1; i<=n; i++){
        int temp = i*i;
        for(int j = i+1; j<=n; j++){
            int temp2 = temp+ j*j;
            if(st.count(temp2)){
                cnt += 2;
            }
        }
       }
       return cnt;
    }
};