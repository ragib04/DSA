class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n, -1);
        
        unordered_map<int, int>NGE;
        stack<int> st;
        for(int i = m-1;i>=0; i--){
            while(!st.empty()){
                if(st.top()>nums2[i]){
                    NGE[nums2[i]] = st.top();
                    break;
                }
                st.pop();
            }
            st.push(nums2[i]);
            
        }
        for(int i = 0; i<n; i++){
            if(NGE.find(nums1[i]) != NGE.end()){
                ans[i] = NGE[nums1[i]];
            }
            else ans[i] = -1;
        }
        return ans;
    }
};