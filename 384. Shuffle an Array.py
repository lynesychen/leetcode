from itertools import permutations

class Solution:

    def __init__(self, nums: List[int]):
        self._orig = nums
        self._current = nums
        self._perm = permutations(nums)
        next(self._perm)
        

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        self._current = self._orig
        return self._current

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        try:
            self._current = next(self._perm)
        except:
            self._perm = permutations(self._orig)
            return self.shuffle()
        return self._current