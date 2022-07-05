class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        val = num // 3
        if num % 3:
            return []
        return [val - 1, val, val + 1]