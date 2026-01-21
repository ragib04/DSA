class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for i in nums:
            if i != 2:
                ans.append(i-((i+1)&(-i-1))//2)
            else:
                ans.append(-1); 


        return ans         