#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

class Solution {
public:
    long long minimumCost(std::string source, std::string target, std::vector<char>& original, std::vector<char>& changed, std::vector<int>& cost) {
        std::vector<std::vector<int>> g(26, std::vector<int>(26, INF));
        int n = source.size();
        int m = original.size();
        
        for(int i = 0; i < m; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w = cost[i];
            g[u][v] = std::min(g[u][v], w);
        }
        
        for(int i = 0; i < 26; i++) {
            g[i][i] = 0;
        }
        
        for(int k = 0; k < 26; k++) {
            for(int u = 0; u < 26; u++) {
                for(int v = 0; v < 26; v++) {
                    if(g[u][k] != INF && g[k][v] != INF) {
                        g[u][v] = std::min(g[u][v], g[u][k] + g[k][v]);
                    }
                }
            }
        }
        
        int64_t ans = 0;
        for(int i = 0; i < n; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if(g[u][v] == INF) {
                return -1;
            }
            ans += g[u][v];
        }
        
        return ans;
    }
};
