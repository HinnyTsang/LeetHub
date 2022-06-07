class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n1 = num1.size();
        int n2 = num2.size();
        string res = string(n1 + n2, '0');
        
        
        for (int i = n1 - 1; i >= 0; --i) {
            
            for (int j = n2 - 1; j >= 0; --j) {
                int curr = res[i+j+1] - '0' + (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = curr%10 + '0';
                res[i+j] += curr / 10;
                
            }
            
        }
        
        // cout << res << endl;
        
        for (int i = 0; i < n1 + n2; ++i) {
            if (res[i] != '0')
                return res.substr(i);
        }
        return "0";
    }
};