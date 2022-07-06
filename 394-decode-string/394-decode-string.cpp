class Solution {
private:
    string decode(string& s, int& i) {
        if (i == s.size())
            return "";
        
        string result;
        
        if (isdigit(s[i])) {
            int mult = s[i++] - '0';
            while(isdigit(s[i]))
                mult = mult * 10 + s[i++] - '0';
            
            ++i;
            string next = decode(s, i);
            
            while (mult-- > 0)
                result += next;
            
            return result + decode(s, i);
        }
        else if (isalpha(s[i])) {
            while(isalpha(s[i])) {
                result += s[i++];
            }
            return result + decode(s, i);
        }
        else if (s[i] == ']') {
            ++i;
            return result;
        }
        return result;
        
    }
public:
    string decodeString(string s) {
        
        int i = 0;
        
        return decode(s, i);

        
    }
};