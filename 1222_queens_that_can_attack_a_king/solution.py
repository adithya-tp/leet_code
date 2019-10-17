class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        pos = king.copy()
        queen_dict = dict()
        for queen in queens:
            queen_dict[tuple(queen)] = True
        flag = 0
        attacks = []
        for i in [-1, 0, 1]:
            for j in [-1, 0, 1]:
                if i == 0 and j == 0:
                    continue
                while((0 <= pos[0] <= 7) and (0 <= pos[1] <= 7) and flag == 0):
                    pos[0] += i
                    pos[1] += j
                    if tuple(pos) in queen_dict:
                        attacks.append(list(pos))
                        flag = 1
                flag = 0
                pos = king.copy()
        return attacks
                
