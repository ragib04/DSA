class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        
        long long ans = 0;
        int curr = 0, prev = 0;
        for(int i = 0; i<n; i++){
            curr = target[i];

            if((curr>0 && prev < 0) || (curr<0 && prev>0)){
                ans += abs(curr);
            }
            else if(abs(curr) > abs(prev)){
                ans += (abs(curr-prev));
            }
            prev = curr;
        }
return ans;
    }
};