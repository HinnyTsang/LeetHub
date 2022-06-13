const buddyStrings = (s: string, goal: string): boolean => {
    
    let fstDiff: boolean = false;
    let sndDiff: boolean = false;
    let [a1, a2, b1, b2]: string [] = [];
    const charSet = new Set<string>();
    
    if (s.length !== goal.length)
        return false;
    
    for (let i = 0; i < s.length; ++i) {
        if (s[i] != goal[i]) {
            if (sndDiff) {
                return false;
            }
            else if (fstDiff) {
                b1 = s[i], b2 = goal[i];
                sndDiff = true;
            }
            else {
                a1 = s[i], a2 = goal[i];
                fstDiff = true;
            }
        }
        charSet.add(s[i]);
    }
    
    return sndDiff ? a1 === b2 && a2 === b1: fstDiff? false: charSet.size !== s.length;
};