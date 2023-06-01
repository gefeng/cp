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
    int maxIncreasingCells(std::vector<std::vector<int>>& mat) {
        int n = mat.size();
        
        std::map<int, std::vector<std::pair<int, int>>> m;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                m[mat[i][j]].emplace_back(i, j);
            }
        }
        
        std::vector<int> dpr(n, 0);
        std::vector<int> dpc(mat[0].size(), 0);
        int ans = 0;
        for(auto& [k, v] : m) {
            std::vector<std::array<int, 3>> nxt;
            for(auto& p : v) {
                int r = p.first;
                int c = p.second;
                
                int max_v = std::max(dpr[r] + 1, dpc[c] + 1);
                nxt.push_back({max_v, r, c});
            }
            
            for(auto& a : nxt) {
                ans = std::max(ans, a[0]);
                dpr[a[1]] = std::max(dpr[a[1]], a[0]);
                dpc[a[2]] = std::max(dpc[a[2]], a[0]);
            }
        }
        
        return ans;
    }
};
