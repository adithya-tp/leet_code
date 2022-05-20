class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        
        # Standardize the scale of numbers by shifting to start from 0
        top -= bottom
        for idx, special_floor in enumerate(special):
            special[idx] -= bottom
        bottom = 0
        n = top + 1
        
        # Brute force, create array of zeros 
        special.sort()
        curr = special[0] if special[0] else 0
        ans = curr
        for special_value in special[1:]:
            ans = max(ans, special_value - curr - 1)
            curr = special_value
        ans = max(ans, top - special[-1])
        return ans
        
        # Create bit string of zeros of length n
        # bit_string = [0 for _ in range(n)]
        # for special_idx in special:
        #     bit_string[special_idx] = 1
        # bit_string = format("".join(map(str, bit_string)), f'0{n}b')
        # print(bit_string)
        
        # Switch on all the bits corresponding to the special floors
        
        # Keep subtracting 1 to get length of consecutive floors without special
        # Track max while repeating this procedure
        
        
        