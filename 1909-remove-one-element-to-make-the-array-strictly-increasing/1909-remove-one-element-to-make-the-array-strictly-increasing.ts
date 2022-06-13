const canBeIncreasing = (nums: number[]): boolean => {
    
    let result: boolean = true;
    let firstRemove: boolean = false;
    let prev: number = 0;
    let pprev: number = 0;
    
    nums.forEach((curr: number) => {
        if (curr <= prev) {
            if (firstRemove) {
                result = false;
                return;
            }
            else {
                if (curr > pprev) {
                    prev = curr;
                }
                firstRemove = true;    
            }
        }
        else {
            pprev = prev;
            prev = curr;
        }
    });
    
    return result;
};