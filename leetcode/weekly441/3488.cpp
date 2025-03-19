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
    std::vector<int> solveQueries(std::vector<int>& nums, std::vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        std::vector<int> ans(m, -1);
    
        std::map<int, std::vector<int>> pos;
        for(int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        for(int i = 0; i < m; i++) {
            int j = queries[i];
            int v = nums[j];
            if(pos.find(v) == pos.end() || pos[v].size() == 1) {
                continue;
            }
            
            int k = std::lower_bound(pos[v].begin(), pos[v].end(), j) - pos[v].begin();
            
            int l = k - 1 >= 0 ? pos[v][k - 1] : pos[v].back();
            int r = k + 1 < pos[v].size() ? pos[v][k + 1] : pos[v][0];
            ans[i] = l < j ? j - l : n - l + j;
            ans[i] = std::min(ans[i], j < r ? r - j : n - j + r);
        }
        
        return ans;
    }
};
