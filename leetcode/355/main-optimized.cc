class Twitter {
public:
    /** Initialize your data structure here. */
    // followees[i] == a list of followees of user i
    vector<int> t;
    unordered_map<int, unordered_set<int>> followees;
    // user_tweets[i] == a list of indices pointing to `t` of user i (like timestamps)
    unordered_map<int, vector<int>> user_tweets;
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // point to t's index (kind of like chronological order)
        user_tweets[userId].push_back(t.size());
        t.push_back(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int counter = 10;
        // n = # of followees for this userId
        // O(n log n + 10 * log n)
        auto cmp = [this](const pair<int, int> &p1, const pair<int, int> &p2) ->
                bool{
            // .first == userid
            // .second == user_tweets[userid]'s index
            // user_tweets[.first][.second] == timestamp
            return user_tweets[p1.first][p1.second] < user_tweets[p2.first][p2.second];
        };
        // Max PQ
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        unordered_set<int> &fs = followees[userId];
        for(int id: fs){
            if(user_tweets[id].size() > 0){
                // .first == userid
                // .second == index
                pq.push({id, user_tweets[id].size()-1});
            }
        }
        if(user_tweets[userId].size() > 0)
            pq.push({userId, user_tweets[userId].size()-1});
        vector<int> feed;
        while(counter > 0 and !pq.empty()){
            int id, index;
            tie(id, index) = pq.top();
            pq.pop();
            feed.push_back(t[user_tweets[id][index]]);
            if(index > 0) pq.push({id, index-1});
            counter--;;
        }
        
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        assert(followerId != followeeId);
        // O(1)
        auto &fs = followees[followerId];
        fs.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        // O(1)
        auto &fs = followees[followerId];
        fs.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
