class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key = lambda x: x[1], reverse=True)
        ans = 0
        for idx, box_type in enumerate(boxTypes):
            box_num, box_unit = box_type
            if truckSize > 0:
                boxes_added = min(truckSize, box_num)
                truckSize -= boxes_added
                ans += (box_unit * boxes_added)
            else:
                break
        return ans
            