class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int ops = 0;
        for(int i = 0; i<n; i++){
            while(!st.empty() && st.top()>nums[i]){
                st.pop();
            }
            if(nums[i] == 0) continue;
            if(st.empty() || st.top()<nums[i]){
                st.push(nums[i]);
                ops++;
                
            }
        }
        return ops;
    }
};

/*
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack(n+1, 0);
        int top = 0, ans = 0;
        for(int num: nums){
            while(stack[top]>num){
                top--;
                ans++;
            }
            if(stack[top] != num){
                stack[++top] = num;
            }
            
        }
        return ans+top;
    }

};
*/