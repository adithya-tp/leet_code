class Solution:
    def trap(self, towers: List[int]) -> int:
        num_towers = len(towers)
        maxLeft = list()
        maxRight = list()
        left_max = 0
        right_max = 0
        for index, tower_height in enumerate(towers):
            left_max = max(towers[index], left_max)
            maxLeft.append(left_max)
            right_max = max(towers[num_towers - index - 1], right_max)
            maxRight.append(right_max)

        water = 0
        for index, tower_height in enumerate(towers):
            water += max(min(maxLeft[index], maxRight[num_towers - index - 1]) - tower_height, 0)

        return water

