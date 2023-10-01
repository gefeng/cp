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
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>>& edges, std::vector<int>& values, int k) {
        std::vector<std::vector<int>> g(n);
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        return dfs(n, g, values, k, 0, -1).first;
    }
    
    std::pair<int, int> dfs(int n, std::vector<std::vector<int>>& g, std::vector<int>& values, int k, int v, int p) {
        int cnt = 0;
        int rem = 0;
        for(int nei : g[v]) {
            if(nei != p) {
                std::pair<int, int> ret = dfs(n, g, values, k, nei, v);
                
                cnt += ret.first;
                rem += ret.second;
                rem %= k;
            }
        }
        
        rem = (rem + values[v]) % k;
        
        if(rem == 0) {
            cnt += 1;
        }
        return {cnt, rem};
    }
};
