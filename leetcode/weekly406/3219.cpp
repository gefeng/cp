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
    int minimumCost(int m, int n, std::vector<int>& horizontalCut, std::vector<int>& verticalCut) {
        int64_t h_cut = 1;
        int64_t v_cut = 1;
        int64_t ans = 0;
        
        std::vector<std::pair<int, int>> cuts;
        
        for(int i = 0; i < m - 1; i++) {
            cuts.emplace_back(horizontalCut[i], 0);
        }
        
        for(int i = 0; i < n - 1; i++) {
            cuts.emplace_back(verticalCut[i], 1);
        }
        
        std::sort(cuts.begin(), cuts.end(), std::greater<std::pair<int, int>>());
        
        for(auto [c, t] : cuts) {
            if(t == 0) {
                ans += c * h_cut;
                v_cut += 1;
            } else {
                ans += c * v_cut;
                h_cut += 1;
            }
        }
        
        return ans;
    }
};
