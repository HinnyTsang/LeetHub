class Solution {
public:
    int hammingWeight(uint32_t n) {
        int one = 0;
        while (n) {
            if (1 & n)
                ++one;
            n >>= 1;
        }
        return one;
    }
};