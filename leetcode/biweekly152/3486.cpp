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
    // sliding windown on tree
    // l is the left boundary on current path downwards
    // dup_pos denotes the depth of the first node of the deepest duplicate nodes pair. 
    // e.g. [a b b a c] dup_pos points to first b in this window
    
    const int MAX = int(5e4);
    
    void dfs(std::vector<std::vector<std::pair<int, int>>>& g, std::vector<int>& nums, int v, int p, int sum, int l, int dup_pos, std::vector<std::vector<int>>& pos, std::vector<int>& path, std::vector<int>& psum, std::vector<int>& ans) {
        int val = nums[v];
        int d = path.size();
        
        psum[d + 1] = sum;
        
        path.push_back(v);
        if(pos[val].size() > 0) {
            int last = pos[val].back();
            l = std::max(l, std::min(dup_pos, last) + 1);
            dup_pos = std::max(dup_pos, last);
        }
        pos[val].push_back(d);
        
        int len = psum[d + 1] - psum[l + 1];
        
        if(len > ans[0]) {
            ans[0] = len;
            ans[1] = d - l + 1;
        } else if(len == ans[0]) {
            ans[1] = std::min(ans[1], d - l + 1);
        }
        
        for(auto [nei, w] : g[v]) {
            if(nei != p) {
                dfs(g, nums, nei, v, sum + w, l, dup_pos, pos, path, psum, ans);
            }
        }
        
        path.pop_back();
        pos[val].pop_back();
    }
    
    std::vector<int> longestSpecialPath(std::vector<std::vector<int>>& edges, std::vector<int>& nums) {
        std::vector<int> ans(2, 0);
        int n = nums.size();
        
        std::vector<std::vector<std::pair<int, int>>> g(n);
        for(auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }
        
        ans[1] = n + 1;

        std::vector<std::vector<int>> pos(MAX + 1);
        std::vector<int> path;
        std::vector<int> psum(n + 1, 0);
        dfs(g, nums, 0, -1, 0, 0, -1, pos, path, psum, ans);
        
        return ans;
    }
};
