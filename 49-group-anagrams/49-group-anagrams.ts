const groupAnagrams = (strs: string[]): string[][] => {
    
    const wordGroup: Map<string, Array<string>> = new Map<string, Array<string>>();
    const result: Array<Array<string>> = new Array<Array<string>>();
    
    strs.forEach((str: string) => {
        const key = str.split('').sort().join('');
        wordGroup.has(key)
            ?wordGroup.get(key).push(str)
            :wordGroup.set(key, [str]);
    });
    

    wordGroup.forEach((value: Array<string>) => {
        result.push(value);
    })
    
    return result; 
};