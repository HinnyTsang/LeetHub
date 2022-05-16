
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

struct Cell {
    PII parent;
    int g,h,f;
    Cell(): 
        parent(-1, -1),
        g(-1), h(-1), f(-1)
    {}
};


class Solution {
private:
    inline static auto compare = [](PIII& a, PIII& b) {
        return a.first > b.first;
    };
    int neib [9] = {-1, 0, 1, 0, -1, -1, 1, 1, -1};
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        /** 
            A* search.
         */
        const int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        // define
        // auto closed = vector<vector<bool>>(n, vector<bool>(n, false));
        auto cells = vector<vector<Cell>>(n, vector<Cell>(n));
        
        priority_queue<PIII, vector<PIII>, decltype(compare)> open(compare);
        
        // closed[0][0] = true;
        cells[0][0].parent={0, 0};
        cells[0][0].g=0;
        cells[0][0].h=(n-1);
        cells[0][0].f=(n-1);
        open.emplace(0,PII(0,0));
        
        while (!open.empty()) {
            
            auto [f, tmp] = open.top(); open.pop();
            auto& [i, j] = tmp;
            
            
            if (i == n-1 && j == n-1) {
                
                int len = 1;
                
                // trace back the path
                while (i != 0 || j != 0) {
                    auto& [a,b] = cells[i][j].parent;
                    cout << i << ", " << j <<  "->" <<a << ", "<< b <<endl;
                    i = a, j = b;
                    ++len;
                }
                
                return len;
            }
            
            
            for (int k = 0; k < 8; ++k) {
                int a = i + neib[k];
                int b = j + neib[k+1];
                
                if (a < 0 || a >= n || b < 0 || b >= n)
                    continue;
                if (grid[a][b] == 1)
                    continue;
                
                int g = cells[i][j].g + 1;
                int h = min(abs(n-1-a), abs(n-1-b));
                int f = g + h;
                
                if (cells[a][b].f == -1 || cells[a][b].f > f) {
                    
                    // cout << a << b << f << endl;
                    cells[a][b].parent = {i,j};
                    cells[a][b].g = g;
                    cells[a][b].h = h;
                    cells[a][b].f = f;
                    open.emplace(f, PII(a, b));
                }
            }
        }
        
        return -1;
    }
};