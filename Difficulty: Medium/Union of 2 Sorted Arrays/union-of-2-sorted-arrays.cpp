class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        vector<int> Union;
        map<int, int> freq;
        for(int i = 0; i<a.size(); i++){
            freq[a[i]]++;
        }
        for(int j = 0; j<b.size(); j++){
            freq[b[j]]++;
        }
        for(auto &it: freq){
            Union.push_back(it.first);
        }
        // return vector with correct order of elements
        return Union;
    }
};