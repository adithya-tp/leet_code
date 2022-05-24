class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        rem = []
        for c, curr in zip(capacity, rocks):
            rem.append(c - curr)
        
        rem.sort()
        
        max_bags = 0
        for _, value in enumerate(rem):
            if value > additionalRocks:
                break
            max_bags += 1
            additionalRocks -= value
            
        return max_bags
            
        