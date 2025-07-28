import heapq

class Solution:
    def minCost(self, parts):
        # code here
        if len(parts) <= 1:
            return 0

        heapq.heapify(parts)
        total_time = 0

        while len(parts) > 1:
            first = heapq.heappop(parts)
            second = heapq.heappop(parts)
            merged = first + second
            total_time += merged
            heapq.heappush(parts, merged)

        return total_time
