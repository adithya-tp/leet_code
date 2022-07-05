class Solution:
    
    def _row_check(self, b):
        for r in range(9):
            count = [0 for _ in range(9 + 1)]
            for c in range(9):
                val = b[r][c]
                if val != -1: count[val] += 1
            if any(t > 1 for t in count):
                return False
        return True
                
    def _transpose(self, b):
        b_t = [[0 for _ in range(9)] for _ in range(9)]
        for r in range(9):
            for c in range(9):
                b_t[r][c] = b[c][r]
        return b_t
    
    def _block_check(self, b):
        for sr in range(0, 9, 3):
            for sc in range(0, 9, 3):
                count = [0 for _ in range(9 + 1)]
                for r in range(sr, sr + 3):
                    for c in range(sc, sc + 3):
                        val = b[r][c]
                        if val != -1: count[val] += 1
                if any(t > 1 for t in count):
                    return False
        return True
    
    def _get_int_board(self, board):
        b = [[-1 for _ in range(9)] for _ in range(9)]
        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val != ".":
                    b[r][c] = int(val)
        return b
        
        
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        b = self._get_int_board(board)
        b_t = self._transpose(b)
        return self._row_check(b) and self._row_check(b_t) and self._block_check(b)