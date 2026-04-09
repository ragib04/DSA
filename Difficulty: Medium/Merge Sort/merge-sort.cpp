class Solution {
  public:
  void merge(vector<int> &arr, int l, int r, int mid){
      vector<int> temp;
      
      int s = l, e = mid+1;
      while(s<=mid && e<=r){
          if(arr[s]<=arr[e]){
              temp.push_back(arr[s]);
              s++;
          }
          else{
              temp.push_back(arr[e]);
              e++;
          }
      }
      while(s<=mid){
          temp.push_back(arr[s]);
          s++;
      }
      while(e<=r){
          temp.push_back(arr[e]);
          e++;
      }
      for(int i = l; i<=r; i++){
          arr[i] = temp[i-l];
      }
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1,r);
        merge(arr, l, r, mid);
    }
};