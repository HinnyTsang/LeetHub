class Solution {
public:
    int calculate(string s) {
        
        stack <char> operation;
        stack <int> nums;
        
        for (int i = 0; i < s.size(); ++i) {
            
            char c = s[i];
            
            if (c == ' ') continue;
            
            else if (isdigit(s[i])) {
                long n = 0;
                while (isdigit(s[i])) {
                    n = 10*n + s[i] - '0';
                    ++i;
                }
                --i;
                            
                if (operation.size() && operation.top() == '/') {
                    operation.pop();
                    int p = nums.top(); nums.pop();
                    p /= n;
                    nums.push(p);
                }
                else if (operation.size() && operation.top() == '*') {
                    operation.pop();
                    int p = nums.top(); nums.pop();
                    p *= n;
                    nums.push(p);
                }
                else {
                    nums.push(n);
                }
            }
            else {
                operation.push(c);
            }
        }
        
        int result = 0;
        
        while (nums.size()) {
            char op = '+';
            if (operation.size() > 0) {
                op = operation.top(); operation.pop();
            }
            if (op == '+') 
                result += nums.top(), nums.pop();
            else if (op == '-') 
                result -= nums.top(), nums.pop();
        }
        
        
        return result;
        
    }
};