class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n<k) return -1;
         int s = arr[0], e = arr[0];
         for(int i = 1;i<n;i++){
             if(arr[i]>s) s = arr[i];
             e += arr[i];
         }
         int ans = -1;
         while(s<=e){
             int max_page = s+(e-s)/2;
             int cnt = 1;
             int page = 0;
             for(int i =0; i<n; i++){
                   if(page+arr[i]>max_page){
                       cnt++;
                       page = 0;
                   }
                   page += arr[i];
             }
             if(cnt>k){
                 s = max_page+1;
             }
             else {
                 ans = max_page;
                 e = max_page-1;
             }
         }
         return ans;
    }
};