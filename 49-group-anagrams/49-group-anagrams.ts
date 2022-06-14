const groupAnagrams = (strs: string[]): string[][] => {
    
    const wordGroup: Map<string, Array<string>> = new Map<string, Array<string>>();
    
    strs.forEach((str: string) => {
        const key = str.split('').sort().join('');
        wordGroup.has(key)
            ?wordGroup.get(key).push(str)
            :wordGroup.set(key, [str]);
    });
    
    
    return [...wordGroup.values()]; 
};