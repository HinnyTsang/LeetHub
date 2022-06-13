type Row = number[];
type Triangle = Row[];

const minimumTotal = (triangle: Triangle): number => {
    
    return triangle.reduceRight((previousValue: Row, currentValue: Row) =>
        currentValue.map((item: number, index: number) => {
            return (
                item + Math.min(previousValue[index], previousValue[index + 1])
            )
        })
    )[0];
};

