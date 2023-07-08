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
    std::vector<int> relocateMarbles(std::vector<int>& nums, std::vector<int>& moveFrom, std::vector<int>& moveTo) {
        std::map<int64_t, int64_t> m;
        for(int x : nums) {
            m[x] += 1;
        }
        
        int n = moveFrom.size();
        for(int i = 0; i < n; i++) {
            int from = moveFrom[i];
            int to = moveTo[i];
            if(m.find(from) != m.end()) {
                m[to] += m[from];
                if(from != to) {
                    m.erase(from);
                }
            }
        }
        
        std::vector<int> ans;
        for(auto& [k, _] : m) {
            ans.push_back(k);
        }
        
        return ans;
    }
};
