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
    int countCompleteSubarrays(std::vector<int>& nums) {
        std::vector<int> cnt(2001, 0);
        for(int x : nums) {
            cnt[x] += 1;
        }
        
        int t = 0;
        for(int x : cnt) {
            if(x) {
                t += 1;
            }
        }
        
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            std::set<int> s;
            for(int j = i; j < n; j++) {
                s.insert(nums[j]);
                if(s.size() == t) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};
