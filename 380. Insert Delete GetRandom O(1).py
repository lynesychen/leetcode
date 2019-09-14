class RandomizedSet(object):

    def __init__(self):
        self.map = {}
        self.mlist = []
    

    def insert(self, val):
        if val not in self.map:
            self.map[val] = len(self.mlist)
            self.mlist.append(val)
            return True
        return False


    def remove(self, val):
        if val in self.map:
            index = self.map[val]
            self.map[self.mlist[-1]] = index
            self.mlist[index] = self.mlist[-1]
            self.mlist.pop()
            del(self.map[val])
            return True
        return False
    

    def getRandom(self):
        if len(self.mlist) == 0:
            return 0
        return random.choice(self.mlist)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()