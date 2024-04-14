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
    long long numberOfSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        int64_t ans = 0;
        
        std::map<int, std::vector<int>> m;
        for(int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
        
        std::vector<int> greater(n, -1);
        std::vector<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[s.back()] <= nums[i]) {
                s.pop_back();
            }
            if(!s.empty()) {
                greater[i] = s.back();
            }
            s.push_back(i);
        }
        
        for(auto& [v, pos] : m) {
            int size = pos.size();
            for(int l = 0, r = 0; r < size; r++) {
                int pre = greater[pos[r]];
                while(l < r && pos[l] < pre) {
                    l += 1;
                }
                ans += r - l + 1;
            }
        }
        
        return ans;
    }
};
