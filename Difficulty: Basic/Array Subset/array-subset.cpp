class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int, int> mp;
        for(auto it: a){
            mp[it]++;
            
        }
        for(auto it: b){
            if(mp.find(it) == mp.end()) return false;
            mp[it]--;
            if(mp[it] == 0) mp.erase(it);
        }
        return true;
        
    }
};