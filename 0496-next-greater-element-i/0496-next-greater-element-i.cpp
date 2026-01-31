class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n, -1);
        vector<int> NGE(m, -1);
        stack<int> st;
        for(int i = m-1;i>=0; i--){
            while(!st.empty()){
                if(st.top()>nums2[i]){
                    NGE[i] = st.top();
                    break;
                }
                st.pop();

            }
            st.push(nums2[i]);
        }
        for(int i = 0; i<n; i++){
            int ele = nums1[i];
            for(int j = 0; j<m; j++){
                if(nums2[j] == ele){
                    ans[i] = NGE[j];
                }
            }
        }
        return ans;
    }
};