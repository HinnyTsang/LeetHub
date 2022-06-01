class Solution {
public:
    bool canMeasureWater_TLE(int x, int y, int z) {
        // TLE solution.
        if (z > x + y) return false;
        
        set<pair<int, int>> seen;
        
        queue<pair<int, int>> bfs; // first jug, sercond jug
        
        seen.insert({0, 0});
        bfs.emplace(0, 0);
        
        while (bfs.size() > 0) {
            int n = bfs.size();
            while (n-- > 0) {
                
                auto [a, b] = bfs.front(); bfs.pop();
                
                if (a == z || b == z || a + b == z)
                    return true;
                
                vector<pair<int, int>> states;
                
                states.push_back({a, y}); // fill the second;
                states.push_back({x, b}); // fill the first;
                states.push_back({0, b}); // empty the first;
                states.push_back({a, 0}); // empty the second;
                states.push_back({min(x, a + b), (a + b >= x)? a + b - x: 0});
                states.push_back({(a + b >= y)? a + b - y: 0, min(y, a + b)});
                
                for (auto s: states) {
                    if (seen.count(s))
                        continue;
                    else {
                        bfs.push(s);
                        seen.insert(s);
                    }
                }
            }
        }
        
        return false;
    }
    
    bool canMeasureWater(int x, int y, int z) {
        // https://leetcode.com/problems/water-and-jug-problem/discuss/83714/A-little-explanation-on-GCD-method.-C%2B%2BJavaPython
        return z == 0 || z <= (long long)x + y && z % __gcd(x, y) == 0;
    }
};