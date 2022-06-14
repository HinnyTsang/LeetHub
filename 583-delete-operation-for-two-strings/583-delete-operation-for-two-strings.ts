const minDistance = (word1: string, word2: string): number => {

    const n: number = word1.length;
    const m: number = word2.length;
    
    let dpCurr: Array<number> = new Array<number>(m + 1).fill(0);
    let dpPrev: Array<number> = new Array<number>(m + 1).fill(0);
    
    for (let i = 1;i <= n; ++i) {
        for (let j = 1; j <= m; ++j) {
            if (word1[i-1] === word2[j-1]) {
                dpCurr[j] = dpPrev[j-1] + 1;
            }
            else {
                dpCurr[j] = Math.max(dpPrev[j], dpCurr[j-1]);
            }
        }
        dpPrev = dpCurr.slice();
    }
    
    
    return n + m - 2 * dpCurr[m];
};