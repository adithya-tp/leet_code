class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        bit_strings = []
        for candidate in candidates:
            # 0 -> padding value
            # 32 -> number of characters to fill
            # b -> format result as binary
            # Source: https://blog.finxter.com/python-bin-function/
            bit_string = format(candidate, "024b")
            bit_strings.append(bit_string)
        
        max_count = 0
        for i in range(24):
            curr_count = 0
            for bit_string in bit_strings:
                if bit_string[i] == '1':
                    curr_count += 1
            max_count = max(max_count, curr_count)
        return max_count