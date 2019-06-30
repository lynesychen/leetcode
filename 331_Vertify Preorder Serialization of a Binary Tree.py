class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        trees_to_see = 1
        for item in preorder.split(","):
            if not trees_to_see:
                return False
            trees_to_see -= 1
            if item != "#":
                trees_to_see += 2
                
        return not trees_to_see     