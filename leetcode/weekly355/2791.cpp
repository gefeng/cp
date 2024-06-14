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
    std::unordered_map<int, int64_t> save_freq;
    std::vector<int> save_mask;

    void dfs(int n, std::vector<std::vector<int>>& g, std::string& s, int v, int mask) {
        save_freq[mask] += 1;
        save_mask[v] = mask;
        
        for(int nei : g[v]) {
            int c = s[nei] - 'a';
            dfs(n, g, s, nei, mask ^ (1 << c));
        }
    }
    
    long long countPalindromePaths(std::vector<int>& parent, std::string s) {
        int n = parent.size();
        std::vector<std::vector<int>> g(n);
        
        for(int i = 0; i < n; i++) {
            int p = parent[i];
            if(p != -1) {
                g[p].push_back(i);
            }
        }
        
        save_mask = std::vector<int>(n, 0);
        
        dfs(n, g, s, 0, 0);
        
        int64_t ans = 0;
        for(int i = 0; i < n; i++) {
            int m = save_mask[i];
            ans += save_freq[m] - 1;
            
            for(int j = 0; j < 26; j++) {
                ans += save_freq[m ^ (1 << j)];
            }
        }
        
        return ans / 2;
    }
};
