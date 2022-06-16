type Row = Array<number>;
type Matrix = Array<Row>;

interface INumMatrix {
    prefixSum: Matrix;
    sumRegion: (row1: number, col1: number, row2: number, col2: number) => number;
}



class NumMatrix implements INumMatrix {
    
    prefixSum: Matrix;

    constructor(matrix: Matrix) {
        
        const n: number = matrix.length;
        const m: number = matrix[0].length;
         
        this.prefixSum = Array.from<Row>({length: n+1});
        
        for (let i = 0; i <= n; ++i) {
            this.prefixSum[i] = Array.from<number>({length: m+1}).fill(0);
        }
        
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < m; ++j) {
                this.prefixSum[i+1][j+1] = this.prefixSum[i][j+1] + this.prefixSum[i+1][j] - this.prefixSum[i][j] + matrix[i][j];
            }
        }
        
    }

    sumRegion(row1: number, col1: number, row2: number, col2: number): number {
        
        [row2, col2] = [row2 + 1, col2 + 1];

        return (this.prefixSum[row2][col2] - this.prefixSum[row2][col1] - this.prefixSum[row1][col2] + this.prefixSum[row1][col1]);
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */