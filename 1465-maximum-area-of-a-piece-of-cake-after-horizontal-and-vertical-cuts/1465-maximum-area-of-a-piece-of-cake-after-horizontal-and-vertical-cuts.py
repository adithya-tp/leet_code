class Solution:
    def maxArea(self, height: int, width: int, horizontal_cuts: List[int], vertical_cuts: List[int]) -> int:
        horizontal_cuts.sort()
        vertical_cuts.sort()
        h = [0] + horizontal_cuts + [height]
        v = [0] + vertical_cuts + [width]
        hmax, vmax = (0, 0)
        
        for idx in range(1, len(h)):
            hmax = max(hmax, h[idx] - h[idx - 1])
        
        for idx in range(1, len(v)):
            vmax = max(vmax, v[idx] - v[idx - 1])
            
        return (hmax * vmax) % (int(1e9 + 7))