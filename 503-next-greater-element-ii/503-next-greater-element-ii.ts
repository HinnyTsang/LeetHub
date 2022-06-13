interface Pair {
    val: number;
    idx: number;
}

const nextGreaterElements = (nums: Array<number>): Array<number> => {
    
    let stack: Array<Pair> = new Array<Pair>();
    const solution: Array<number> = new Array<number>(nums.length);
    
    nums.forEach((curr: number, i: number) => {
        while (stack.length > 0 && stack[stack.length-1].val < curr) {
            const prev: Pair = stack.pop();
            solution[prev.idx] = curr;
        }
        stack.push({val: curr, idx: i});
    });
    
    nums.forEach((curr: number, i: number) => {
        while (stack.length > 0 && stack[stack.length-1].val < curr) {
            const prev: Pair = stack.pop();
            solution[prev.idx] = curr;
        }
    });
    
    stack.forEach((pair: Pair) => {
        solution[pair.idx] = -1;
    }); 
    
    return solution;
};