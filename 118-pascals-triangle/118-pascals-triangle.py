class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        n = [[1]]
        for i in range(1, numRows):
            row = [1]
            for j in range(i - 1):
                row.append(n[-1][j] + n[-1][j + 1])
            row.append(1)
            n.append(row)
        return n
        