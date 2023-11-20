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
    std::vector<int> leftmostBuildingQueries(std::vector<int>& heights, std::vector<std::vector<int>>& queries) {
        int n = heights.size();
        int m = queries.size();
        
        std::vector<std::pair<int, int>> a(n);
        std::vector<std::array<int, 4>> b(m);
    
        for(int i = 0; i < n; i++) {
            a[i] = {heights[i], i};
        }
        
        for(int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            b[i] = {std::max(heights[l], heights[r]), std::min(l, r), std::max(l, r), i};
        }
        
        std::sort(a.begin(), a.end(), std::greater<std::pair<int, int>>()); 
        std::sort(b.begin(), b.end(), [](const auto& x, const auto& y) {
            return x[0] > y[0];
        });
        
        std::vector<int> ans(m, -1);
        std::set<int> pos;
        for(int i = 0, j = 0; i < m; i++) {
            while(j < n && a[j].first > b[i][0]) {
                pos.insert(a[j].second);
                j += 1;
            }
            
            if(b[i][1] == b[i][2]) {
                ans[b[i][3]] = b[i][1];
                continue;
            }
            
            if(heights[b[i][1]] < heights[b[i][2]]) {
                ans[b[i][3]] = b[i][2];
                continue;
            }
            
            auto it = pos.upper_bound(b[i][2]);
            if(it != pos.end()) {
                ans[b[i][3]] = *it;
            } 
        }
        
        return ans;
    }
};
