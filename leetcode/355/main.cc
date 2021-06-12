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
        // O(# of followee for this userId^2 * 10)
        // Get a list of followee related to userId
        unordered_set<int> &fs = followees[userId];
        // cursor[id] == a index pointing to user_tweets[id] (a vector)
        unordered_map<int, int> cursor;
        if(user_tweets[userId].size() > 0) cursor[userId] = user_tweets[userId].size()-1;
        for(int id: fs){
            if(user_tweets[id].size() > 0){
                cursor[id] = user_tweets[id].size()-1; // point to the most recent
            }
        }
        vector<int> feed;
        while(counter > 0 and !cursor.empty()){
            // Select the one with the largest index (most recent)
            auto most_recent = cursor.begin();
            for(auto it = cursor.begin(); it != cursor.end(); it++){
                int fid = it->first;
                int timestamp = user_tweets[fid][it->second];
                // this is more recent
                if(timestamp > user_tweets[most_recent->first][most_recent->second]){
                    most_recent = it;
                }
            }
            int time_idx = user_tweets[most_recent->first][most_recent->second];
            // This user id is running out of tweets
            if(most_recent->second == 0) cursor.erase(most_recent->first);
            else most_recent->second--; // move the cursor

            feed.push_back(t[time_idx]);
            counter--;
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
