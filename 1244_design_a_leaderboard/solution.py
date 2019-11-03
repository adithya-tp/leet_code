class Leaderboard:

    def __init__(self):
        self.lb = dict()
        self.max_k = list()

    def addScore(self, playerId: int, score: int) -> None:
        try:
            self.lb[playerId] += score
        except:
            self.lb[playerId] = score

    def top(self, K: int) -> int:
        return sum(sorted(list(self.lb.values()), reverse=True)[:K])
        

    def reset(self, playerId: int) -> None:
        del self.lb[playerId]
