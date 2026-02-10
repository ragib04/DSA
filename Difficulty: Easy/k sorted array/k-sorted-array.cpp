// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
       bool found = true;
        priority_queue<pair<int , int>> pq;
        for(int i = 0; i < n ; i++){
            pq.push({arr[i] , i});
        }
        int exp = n-1;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            if(abs(exp - idx) > k) {
                found = false;
                break;
            }
            exp--;
            
        }
        
        return found == true ? "Yes" : "No";
    }
};