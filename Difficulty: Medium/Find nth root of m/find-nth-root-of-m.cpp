class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
      
        int s = 1, e = m;
        if(m == 0) return 0;
     
        while(s<=e){
            int mid = s+(e-s)/2;
            long long root = 1;
            for(int i = 0; i<n; i++){
                root *= mid;
            }
            if(root == m) return mid;
            if(root>m) e = mid-1;
            else {
                s = mid+1;
            }
        }
        return -1;
    }
};