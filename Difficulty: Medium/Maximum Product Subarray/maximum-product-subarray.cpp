class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int currmax= arr[0];
        int currmin = arr[0];
        
        int ans = arr[0];
        for(int i = 1; i<n; i++){
            if(arr[i]<0) swap(currmax, currmin);
            currmax = max(currmax*arr[i], arr[i]);
            currmin = min(currmin*arr[i], arr[i]);
            ans = max(ans, currmax);
            
        }
        return ans;
    }
};//min = -2, max = -2
