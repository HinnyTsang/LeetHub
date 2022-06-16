const findPalindrome = (s: string, l: number, r: number): Array<number> => {
    
    while (l >= 0 && r < s.length && s[l] === s[r]) {
        --l, ++r;
    }
    
    return [l + 1, r];
}

const longestPalindrome = (s: string): string => {
    
    let l: number = 0;
    let r: number = 0;
    
    for (let i: number = 0; i < s.length; ++i) {
        
        var [a, b] = findPalindrome(s, i, i);
        var [c, d] = findPalindrome(s, i, i+1);
        
        if (b - a > r - l) {
            l = a;
            r = b;
        }
        if (d - c > r - l) {
            l = c;
            r = d;
        }
    }
    
    return s.substring(l, r);
};