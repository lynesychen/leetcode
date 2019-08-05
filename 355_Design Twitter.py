class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.users = {}
        self.time = 1

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: None
        """
        if userId not in self.users: 
            self.users[userId] = {'tweet':[],'follow':[]}
        self.users[userId]['tweet'].insert(0,(self.time,tweetId))
        self.time += 1
        
    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        if userId not in self.users:
            self.users[userId] = {'tweet':[],'follow':[]}
        tweets,count = [self.users[userId]['tweet']],len(self.users[userId]['tweet'])
        for user in self.users[userId]['follow']: 
            tweets.append(self.users[user]['tweet'])
            count += len(self.users[user]['tweet'])
        length,index,result = len(tweets),[0]*len(tweets),[]
        for cnt in range(min(10,count)):
            mymax,maxi = (0,0),-1
            for i in range(length):
                if index[i]>len(tweets[i])-1: continue
                if tweets[i][index[i]]>mymax: mymax,maxi = tweets[i][index[i]],i
            index[maxi] += 1
            result.append(mymax[1])
        return result
        
    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        if followerId not in self.users:
            self.users[followerId] = {'tweet':[],'follow':[]} 
        if followeeId not in self.users:
            self.users[followeeId] = {'tweet':[],'follow':[]} 
        if followerId==followeeId or followeeId in self.users[followerId]['follow']: return
        self.users[followerId]['follow'].append(followeeId)

    
    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """
        if followerId not in self.users: 
            self.users[followerId] = {'tweet':[],'follow':[]}
        if followeeId not in self.users:
            self.users[followeeId] = {'tweet':[],'follow':[]} 
        if followeeId not in self.users[followerId]['follow'] or \
        followerId==followeeId: return
        self.users[followerId]['follow'].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)