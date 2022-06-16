const smallestRangeII = (nums: number[], k: number): number => {

    let max: number = Math.max(...nums);
    let min: number = Math.min(...nums);
    let dif: number = max - min;
    
    if (dif <= k)
        return dif;
    
    const r = nums.length - 1;
    
    nums.sort((a: number, b: number): number => a - b );

    // a[0] + k, a[1] + k, ... a[i] + k, a[i + 1] - k, ... a[r] - k;
    
    for (let i = 0; i < r; ++i) {
        max = Math.max(nums[i] + k, nums[r] - k);
        min = Math.min(nums[0] + k, nums[i + 1] - k);
        dif = Math.min(dif, max - min);
    }

    return dif;
};