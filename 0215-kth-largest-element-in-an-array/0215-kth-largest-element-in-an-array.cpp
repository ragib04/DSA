class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      //  priority_queue<int> pq; //maxH ele on the top
        priority_queue<int, vector<int>, greater<int>> pq;//minH
        for(int i =0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return (pq.top());
    }
};