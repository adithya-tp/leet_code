class Solution:
    
    def dfs(self, u, graph, dis):
        neighbour = graph[u]
        if (neighbour == -1) or (dis[neighbour] != -1):
            return
        dis[neighbour] = dis[u] + 1
        self.dfs(neighbour, graph, dis)
    
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        num_nodes = len(edges)
        d1 = [-1 for _ in range(num_nodes)]
        d2 = [-1 for _ in range(num_nodes)]
        
        d1[node1] = 0
        d2[node2] = 0
        self.dfs(node1, edges, d1)
        self.dfs(node2, edges, d2)
        
        min_dis = 1e15
        min_dis_node_idx = -1
        for node_idx in range(num_nodes):
            if (d1[node_idx] != -1) and (d2[node_idx] != -1):
                max_dis = max(d1[node_idx], d2[node_idx])
                if max_dis < min_dis:
                    min_dis = max_dis
                    min_dis_node_idx = node_idx
                elif max_dis == min_dis:
                    if node_idx < min_dis_node_idx:
                        min_dis_node_idx = node_idx
        return min_dis_node_idx