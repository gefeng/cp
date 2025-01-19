#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int MAX = int(5e4);
constexpr int INF = int(1e9);

class Solution {
public:
    void dfs_1(std::vector<std::vector<std::pair<int, int>>>& g, int v, int p, std::vector<int>& to_root, std::vector<int>& depth) {
        for(auto [nei, w] : g[v]) {
            if(nei != p) {
                to_root[nei] = to_root[v] + w;
                depth[nei] = depth[v] + 1;
                dfs_1(g, nei, v, to_root, depth);
            }
        }
    }
    
    void dfs_2(std::vector<std::vector<std::pair<int, int>>>& g, std::vector<int>& nums, std::vector<int>& to_root, std::vector<int>& depth, std::vector<std::vector<std::pair<int, int>>>& seen, int v, int p, int x, std::vector<int>& ans) {
        int nx = 0;
        if(v == 0) {
            ans[0] = 0;
            ans[1] = 1;
            x = 0;
        } else {
            int k = nums[v];
            std::pair<int, int> pre = seen[k].empty() ? std::pair<int, int>(-1, -1) : seen[k].back();
            int from = pre.first == -1 || depth[x] > depth[pre.second] ? x : pre.second;
            int len = to_root[v] - to_root[from];
            if(len > ans[0]) {
                ans[0] = len;
                ans[1] = depth[v] - depth[from] + 1;
            } else if(len == ans[0]) {
                ans[1] = std::min(ans[1], depth[v] - depth[from] + 1);
            }
            
            nx = from;
        }
        
        for(auto [nei, w] : g[v]) {
            if(nei != p) {
                seen[nums[v]].emplace_back(v, nei);
                dfs_2(g, nums, to_root, depth, seen, nei, v, nx, ans);
                seen[nums[v]].pop_back();
            }
        }
    }
    
    std::vector<int> longestSpecialPath(std::vector<std::vector<int>>& edges, std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(2);
        std::vector<std::vector<std::pair<int, int>>> g(n);
        
        for(int i = 0; i < n - 1; i++) {
            g[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
            g[edges[i][1]].emplace_back(edges[i][0], edges[i][2]);
        }
        
        std::vector<int> to_root(n, 0);
        std::vector<int> depth(n, 0);
        dfs_1(g, 0, -1, to_root, depth);
        
        std::vector<std::vector<std::pair<int, int>>> seen(MAX + 1);
        dfs_2(g, nums, to_root, depth, seen, 0, -1, -1, ans);
        
        return ans;
    }
};
