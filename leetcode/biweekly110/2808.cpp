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
    int minimumSeconds(std::vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        std::map<int, std::vector<int>> m;
        for(int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
        
        for(auto& [k, v] : m) {
            int cnt = (v.front() + n - v.back()) / 2;
            int sz = v.size();
            for(int i = 1; i < sz; i++) {
                int d = v[i] - v[i - 1] - 1;
                cnt = std::max(cnt, (d + 1) / 2);
            }
            
            ans = std::min(ans, cnt);
        }
        
        return ans;
    }
};
