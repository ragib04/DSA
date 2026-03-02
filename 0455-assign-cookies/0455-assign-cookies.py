class Solution:

    """
    to satisfy many children as possible, we want to assign the minimum 
    sufficient cookie to the that child. 
    >so we can easly sort g and s
    >and use two pointer one for child g and one for cookie s 
    >assign the smallest cookie that satisfies them
    >if satisfied then move to next child and always move to next cookie

    T.C-> NlogN + mlogm for sorting
    space:- O(1)
    """
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        n = len(g)
        m = len(s)
        i,j = 0,0
        while i<n and j<m:
            if g[i] <= s[j]:
                i += 1

            j += 1

        return i        
