#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    long long getMaxFunctionValue(std::vector<int>& receiver, long long k) {
        int n = receiver.size();
        std::vector<std::vector<int>> nxt(40, std::vector<int>(n, 0));
        std::vector<std::vector<int64_t>> sum(40, std::vector<int64_t>(n, 0));
        
        for(int i = 0; i < n; i++) {
            nxt[0][i] = receiver[i];
            sum[0][i] = receiver[i];
        }
        
        for(int i = 1; i < 40; i++) {
            for(int j = 0; j < n; j++) {
                nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
                sum[i][j] = sum[i - 1][j] + sum[i - 1][nxt[i - 1][j]];
            }
        }
        
        int64_t ans = 0;
        for(int i = 0; i < n; i++) {
            int64_t score = i;
            int p = i;
            for(int j = 0; j < 40; j++) {
                if(k & ((int64_t)1 << j)) {
                    int np = nxt[j][p];
                    score += sum[j][p];
                    std::swap(np, p);
                }
            }
            ans = std::max(ans, score);
        }
        
        return ans;
    }
};
