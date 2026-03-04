import heapq
class Solution:
    def fractionalKnapsack(self, val, wt, capacity):
        #code here
        
        """
           /*
  intitution:- always pick item greedly bansed on their value to wt ratio.
        take the item with the highest ratio firsr then the next highest 
        until the lnapsack is full.
        then take fractional part acc to remaning capacity.
        
        >take priorty que for max ratio on top
        >push (val/wt) ratio for each item
        >iterate through item
        if curr item fully fit add its val and dec the capacity
        else take the fractional part that fits and add proportional val
        
        */
        """
        n = len(val)
        pq = []

        for i in range(n):
            ratio = val[i] / wt[i]
            heapq.heappush(pq, (-ratio, wt[i]))  # max heap

        profit = 0.0

        while capacity > 0 and pq:
            ratio, weight = heapq.heappop(pq)
            ratio = -ratio

            if weight <= capacity:
                profit += ratio * weight
                capacity -= weight
            else:
                profit += capacity * ratio
                capacity = 0

        return profit        
            