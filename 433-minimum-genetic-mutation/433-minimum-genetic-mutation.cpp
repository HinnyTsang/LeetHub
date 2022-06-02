class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> seen;
        queue<string> bfs;
        unordered_map<char, int> gene_to_idx = {
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}
        };
        vector<int> idx_to_gene = {'A', 'C', 'G', 'T'};
        int num_of_mutation = 0;
        
        // check rather the gene is mutated.
        for (string& gene: bank)
            seen[gene] = false;
        
        // if the result is not in the bank.
        if (!seen.count(end)) return -1;
        
        // initilize bfs
        bfs.push(start);
        
        while (!bfs.empty()) {
            int n = bfs.size();
            while (n-- > 0) {
                string curr = bfs.front(); bfs.pop();
                if (curr == end)
                    return num_of_mutation;
                
                for (int i = 0; i < curr.size(); ++i) {
                    int idx = gene_to_idx[curr[i]];
                    for (int j = 0; j < 4; ++j) {
                        idx = (idx + 1)%4;
                        curr[i] = idx_to_gene[idx];
                        if (seen.count(curr) &&
                            !seen[curr]) {
                            bfs.push(curr);
                            seen[curr] = true;
                        }
                    }
                }
            }
            ++num_of_mutation;
        }
        
        return -1;
    }
};