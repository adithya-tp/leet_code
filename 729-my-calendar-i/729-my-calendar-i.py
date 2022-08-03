class MyCalendar:
    def __init__(self):
        self.intervals = []
        
    
    def overlaps(self, i1, i2):
        start_max = max(i1[0], i2[0])
        end_min = min(i1[1], i2[1])
        return end_min - start_max > 0

    def book(self, start: int, end: int) -> bool:
        for interval in self.intervals:
            if self.overlaps(interval, (start, end)):
                return False
        self.intervals.append((start, end))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)