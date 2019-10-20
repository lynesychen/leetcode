class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        ln = len(people)
        if ln == 0:
            return []
        people = sorted(people, key = lambda x: (-x[0], x[1]))
        ls = []
        for pep in people:
            ls.insert(pep[1], pep)
        return ls
