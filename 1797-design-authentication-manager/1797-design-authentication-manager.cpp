

class AuthenticationManager {
private:
    int timeOut;
    unordered_map<string, int> tokens;
    
public:
    AuthenticationManager(int timeToLive) {
        timeOut = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + timeOut;
    }
    
    void renew(string tokenId, int currentTime) {
        if (tokens.count(tokenId) && tokens[tokenId] > currentTime)
            tokens[tokenId] = currentTime + timeOut;
    }
    
    int countUnexpiredTokens(int currentTime) {
        
        vector<string> expiredTokens;
        
        for (auto& [token, expiredTime]: tokens) {
            if (expiredTime <= currentTime) {
                expiredTokens.push_back(token);
            }
        }
        
        for (auto& token: expiredTokens) {
            tokens.erase(token);
        }
        
        return tokens.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */