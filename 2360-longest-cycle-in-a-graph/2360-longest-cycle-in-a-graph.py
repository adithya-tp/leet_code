class Solution:
    
    def __init__(self):
        self.ans = -1
        self.cycle_num = None
    
    def dfs(self, node_idx, g, vis, path):
        if vis[node_idx]:
            found = False
            sub = 0
            for val in path:
                if val == node_idx:
                    found = True
                    break
                sub += 1
            if found:
                self.ans = max(self.ans, len(path) - sub)
            return
        
        neighbour = g[node_idx]
        if (neighbour == -1):
            return
        
        path.append(node_idx)
        vis[node_idx] = True
        self.dfs(neighbour, g, vis, path)
    
    def longestCycle(self, edges: List[int]) -> int:
        num_nodes = len(edges)
        vis = [False for _ in range(num_nodes)]
        self.cycle_num = [-1 for _ in range(num_nodes)]
        for node_idx in range(num_nodes):
            if not vis[node_idx]:
                self.dfs(node_idx, edges, vis, [])
        return self.ans