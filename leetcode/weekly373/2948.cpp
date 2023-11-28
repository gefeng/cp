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
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        
        std::vector<std::pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {nums[i], i};
        }
        
        std::sort(a.begin(), a.end());
        
        std::vector<int> ans(n);
        for(int i = 0; i < n; ) {
            int j = i;
            std::vector<int> pos;
            while(i < n && (i == j || a[i].first - a[i - 1].first <= limit)) {
                pos.push_back(a[i].second);
                i += 1;
            }
            
            std::sort(pos.begin(), pos.end());
            for(int k = 0; k < i - j; k++) {
                ans[pos[k]] = a[j + k].first; 
            }
        }
        
        return ans;
    }
};
