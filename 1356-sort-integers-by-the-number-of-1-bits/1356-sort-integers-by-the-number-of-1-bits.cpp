class Solution {
private:
    static int count_bit(int n) {
        int count = 0;
        
        while (n > 0) {
            if (n & 1)
                ++count;
            n >>= 1;
        }
        return count;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), 
            [](int a, int b) {
                int na = count_bit(a);
                int nb = count_bit(b);
                
                if (na == nb)
                    return a < b;
                
                return na < nb;
            });
        return arr;
    }
};