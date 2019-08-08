class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        def GCD(x,y):
            if not y: 
                return x
            else:
                return GCD(y,x%y)
 
        if x+y<z or (z!=0 and z%GCD(x,y)):
            return False
        else:
            return True