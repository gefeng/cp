#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

class Solution {
public:
    long long maxSpending(std::vector<std::vector<int>>& values) {
        int m = values.size();
        int n = values[0].size();
        int64_t ans = 0;
        std::vector<int> last(m, n - 1);
        for(int d = 1; d <= m * n; d++) {
            int min_v = INF;
            int min_p = -1;
            for(int i = 0; i < m; i++) {
                int p = last[i];
                if(p >= 0 && values[i][p] < min_v) {
                    min_v = values[i][p];
                    min_p = i;
                }
            }
            
            ans += (int64_t)min_v * d;
            last[min_p] -= 1;
        }
        
        return ans;
    }
};
