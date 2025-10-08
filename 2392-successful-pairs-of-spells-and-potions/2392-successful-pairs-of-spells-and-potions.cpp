class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
vector<int> ans;
        for(int i = 0; i<n; i++){
            int cnt  = 0;
           int s = 0, e = m-1;
           int idx = m;
           while(s<=e){
            int mid = (s+e)/2;
            long prod = (long)spells[i]*potions[mid];
            if(prod>=success){
                idx = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }

           }
          
          
            ans.push_back(m-idx);
        }
        return ans;
    }
};