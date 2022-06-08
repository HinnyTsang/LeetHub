class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i = n - 1, carry = 0;
        
        while (i >= 0) {
            num[i] += k % 10 + carry;
            carry = num[i] / 10;
            num[i] %= 10;
            k /= 10;
            --i;
        }
        while (k > 0 || carry) {
            num.insert(num.begin(), carry + k%10);
            carry = num[0] / 10;
            num[0] %= 10;
            k /= 10;
        }
        return num;
    }
};