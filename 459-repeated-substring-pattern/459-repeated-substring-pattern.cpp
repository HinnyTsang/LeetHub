class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.size(), len = 0;
        vector<int> table(n, 0);
        
        
        for (int i = 1; i < n;) {
            if (s[i] == s[len]) {
                table[i++] = ++len;
            }
            else if (len == 0) {
                ++i;
            } 
            else {
                len = table[len-1];
            }
        }
        
//         for (int& i: table) 
//             cout << i << endl;
        
        return table.back() && table.back() % (n-table.back()) == 0;
    }
};