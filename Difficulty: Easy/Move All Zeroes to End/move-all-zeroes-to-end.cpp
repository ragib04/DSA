// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int i=0;
        
        for(int j=0;j<arr.size();j++){
            if(arr[j]==0){
                if(arr[i]==0){
                    continue;
                }else{
                    i=j;
                }
            }
            else{
                if(arr[i]!=0){
                    continue;
                }
                else{
                    swap(arr[i],arr[j]);
                    i++;
                }
            }
        }
        
    }
};