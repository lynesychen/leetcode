import random
class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> List[float]:
        while True:
            x_ = random.random() - 0.5
            y_ = random.random() - 0.5

            if x_ ** 2 + y_ ** 2 < 0.25:
                diameter = 2 * self.radius
                return self.x_center + x_ * diameter, self.y_center + y_ * diameter
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
