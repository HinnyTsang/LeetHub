class SeatManager {
private:
    set<int> unreserved;
    vector<bool> reserved;
    int n;
public:
    SeatManager(int _n): n(_n) {
        unreserved.insert(1);
        reserved = vector<bool>(n + 1, false);
    }
    
    int reserve() {
        int curr = *unreserved.begin();
        unreserved.erase(curr);
        
        reserved[curr] = true;
        
        if (curr < n && reserved[curr + 1] == false) {
            unreserved.insert(curr + 1);
        } 
        
        return curr;
    }
    
    void unreserve(int seatNumber) {
        reserved[seatNumber] = false;
        unreserved.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */