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
    std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::set<int> s1(nums1.begin(), nums1.end());
        std::set<int> s2(nums2.begin(), nums2.end());
        
        std::vector<int> ans(2, 0);
        for(int x : nums1) {
            if(s2.find(x) != s2.end()) {
                ans[0] += 1;
            }
        }
        
        for(int x : nums2) {
            if(s1.find(x) != s1.end()) {
                ans[1] += 1;
            }
        }
        
        return ans;
    }
};
