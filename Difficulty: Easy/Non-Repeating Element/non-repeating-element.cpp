
class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // Complete the function
        int ans = 0;
        unordered_map<int, int>mp;
        for(int i =0; i<arr.size(); i++){
                mp[arr[i]]++;
            }
        for(int i = 0; i<arr.size(); i++){
            if(mp[arr[i]] == 1){
                ans = arr[i];
                break;
            }
        }
        return ans;
    }
};

/*
-1 , 1

*/
