from bisect import bisect_left
class Solution:
    # @param A : list of list of integers
    # @return an integer
    # T.c- O(nlogn)
    #s.c- O(N)
    """
    1. Sort (w ↑, h ↓)
    2. For each height:
      find position using binary search
      replace or append
    3. Return size of temp
    """

    def maxEnvelopes(self, arr):
        arr.sort(key=lambda x: (x[0], -x[1]))
        envlopInside = []
        for i in range(len(arr)):
            height = arr[i][1]
            ind = bisect_left(envlopInside, height)

            if ind >= len(envlopInside):
                envlopInside.append(height)   # ✅ fixed
            else:
                envlopInside[ind] = height

        return len(envlopInside)
       
#hm chatgrp dekha rhe smjh aaye to dekhye hm que nhi smjhe wo kiya pucha
        
        """
        if ind >= len(envlopInside):
    envlopInside.append(ind)   # ❌ WRONG


    ind is just the position returned by binary search.

        You should append the actual height.

        Because LIS is built using heights.
        """






