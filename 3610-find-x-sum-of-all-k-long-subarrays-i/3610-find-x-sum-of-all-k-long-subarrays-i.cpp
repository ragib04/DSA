class Solution {
public:
int func( priority_queue<pair<int,int>> &pq, int x){
    int sum = 0;
    while(!pq.empty() && x>0){
            auto [freq, ele] = pq.top();
            pq.pop();
            
            sum += freq*ele;
            x--;

        }
        return sum;
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n = nums.size();
        vector<int> ans(n-k+1);
        
        for(int i = 0; i<=n-k; i++){
            unordered_map<int, int> mp;
            for(int j = i; j<k+i; j++){
                mp[nums[j]]++;
            }
            priority_queue<pair<int,int>> pq;
        for(auto i: mp){
            pq.push({i.second, i.first});
        }
        int x_sum = func(pq,x);
        ans[i] = x_sum;
        }

    
    return ans;
    }
};
