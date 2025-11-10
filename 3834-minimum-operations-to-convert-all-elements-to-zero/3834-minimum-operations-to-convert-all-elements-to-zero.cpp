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