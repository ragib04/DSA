class Solution {
  public:
  int n;
  bool ispossible(vector<int> &stalls, int k, int guess){
      int cnt_cow = 1;
      int prev = stalls[0];
      for(int i = 1; i<n; i++){
          if(stalls[i]-prev >= guess){
              cnt_cow++;
              prev = stalls[i];
          }
      }
      return cnt_cow>=k ? true: false;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int ans = INT_MIN;
        int s = 1, e = stalls[n-1]-stalls[0];
        while(s<=e){
            int mid = s+(e-s)/2;
            if(ispossible(stalls, k, mid)){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }
};