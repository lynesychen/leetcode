class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rowDict = []
        colDict = []
        gridDict = []
        
        for i in xrange(9):
            rowDict.append([])
            colDict.append([])
            gridDict.append([])
        
        for i in xrange(0,9):
            for j in xrange(0,9):
                curVal = board[i][j]

                if curVal == '.':
                    continue
                if curVal in rowDict[i]:
                    return False
                else:
                    rowDict[i].append(curVal)
                
                if curVal in colDict[j]:
                    return False
                else:
                    colDict[j].append(curVal)
                    
           
                grid = (i/3)*3+j/3
                if curVal in gridDict[grid]:
                    return False
                else:
                    gridDict[grid].append(curVal)
        return True