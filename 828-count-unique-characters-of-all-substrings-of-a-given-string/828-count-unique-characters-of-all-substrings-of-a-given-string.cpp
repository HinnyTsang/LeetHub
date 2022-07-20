class Solution {
public:
    int uniqueLetterString(string s) {

        int n = s.size(), result = 0;
        vector<vector<int>> seen(2, vector<int>(26, -1));
        
        for (int i = 0; i < n; ++i) {
            
            int c = s[i] - 'A';
            int l = (seen[1][c] - seen[0][c]);
            int r = (i - seen[1][c]);
            
            seen[0][c] = seen[1][c];
            seen[1][c] = i;
            
            result += l * r;
        }
        
        
        for (int i = 0; i < 26; ++i) {
            result += (seen[1][i] - seen[0][i]) * (n - seen[1][i]);
        }
        
        
        return result;
    }
    
    int uniqueLetterString_TLE(string s) {

        vector<int> seen(26, 0);
        
        int n_chars = 0;
        int result = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            
            ++seen[s[i] - 'A'];
            
            if (seen[s[i] - 'A'] == 2)
                n_chars -= 1;
            if (seen[s[i] - 'A'] == 1) 
                n_chars += 1;
            
            vector<int> curr = seen;
            int curr_char = n_chars;
            
            result += curr_char;
            
            for (int j = 0; j < i; ++j) {
                
                --curr[s[j] - 'A'];
                if (curr[s[j] - 'A'] == 1)
                    ++curr_char;
                if (curr[s[j] - 'A'] == 0) {
                    --curr_char;
                }
                
                result += curr_char;
            }
            
        }
        
        
        return result;
    }
};