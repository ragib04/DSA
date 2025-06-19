class Solution {
  public:
  void merge(vector<int>& arr,int l,int mid, int r){
      vector<int>temp;
      int start=l,end=mid+1;
      while(start<=mid && end<=r){
          if(arr[start]<=arr[end]){
              temp.push_back(arr[start]);
              start++;
          }
          else{
              temp.push_back(arr[end]);
              end++;
          }
          
        }
        while(start<=mid){
            temp.push_back(arr[start]);
            start++;
        }
        while(end<=r){
            temp.push_back(arr[end]);
            end++;
        }
        for(int i=l;i<=r;i++){
            arr[i]=temp[i-l];
        }
  
      
  }
  void ms(vector<int>& arr, int l, int r){
      if(l>=r)
      return;
      int mid=(l+r)/2;
      ms(arr,l,mid);
      ms(arr,mid+1,r);
      merge(arr,l,mid,r);
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        int n=arr.size();
        ms(arr,0,n-1);
       
    }
};