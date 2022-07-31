class Solution:
    def maximumGroups(self, grades: List[int]) -> int:
        start_idx = 0
        end_idx = 1
        
        grps = 0
        grp_size = 1
        while True:
            s = sum(grades[start_idx: end_idx])
            if (end_idx - start_idx) != grp_size:
                break
            
            grps += 1
            if end_idx == len(grades):
                break
            grp_size += 1
            start_idx = end_idx
            end_idx = min(len(grades), end_idx + grp_size)
        return grps