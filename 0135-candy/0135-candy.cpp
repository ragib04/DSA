class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        int n = ratings.size();
         vector<int> ans(n,1);
         for(int i = 1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]){
                    ans[i] = ans[i-1]+1;
            }
            
         }
         for(int i = n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                ans[i] = max(ans[i], ans[i+1]+1);
            }
         }
        //  sum = accumulate(ans.begin(), ans.end(), 0);
        for(int i = 0; i<n; i++){
            sum += ans[i];
        }
         
         return sum;
    }
};